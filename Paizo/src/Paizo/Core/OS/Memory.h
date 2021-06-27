#pragma once

#include "Templates/RefCount.h"
#include "Core.h"
#include <stddef.h>

#ifndef PAD_ALIGN
#define PAD_ALIGN 16 //must always be greater than this at much
#endif

#define DEBUG_ENABLED

class Memory
{
	Memory();
#ifdef DEBUG_ENABLED
	static SafeNumeric<uint64_t> memUsage;
	static SafeNumeric<uint64_t> maxUsage;
#endif

	static SafeNumeric<uint64_t> allocCount;
public:
	static void* AllocStatic(size_t p_bytes, bool p_padAlign = false);
	static void* ReAllocStatic(void* p_memory, size_t p_bytes, bool p_padAlign = false);
	static void FreeStatic(void* p_ptr, bool p_padAlign = false);

	static uint64_t GetAvailableMem();
	static uint64_t GetMemUsage();
	static uint64_t GetMaxMemUsage();

};

class DefaultAllocator
{
public:
	__forceinline static void* alloc(size_t p_memory) { return Memory::AllocStatic(p_memory, false); }
	__forceinline static void* Free(void* p_ptr) { Memory::FreeStatic(p_ptr, false); }
};

//class StackAllocator
//{
//public:
//	typedef uint32_t Marker;
//
//	// constructs a new allocator with the given total size;
//	explicit StackAllocator(uint32_t stackSizeBytes);
//
//	// Allocates a new block of the given size from stack top
//	void* Alloc(uint32_t sizeBytes);
//	Marker GetMarker();
//	void FreeToMarker(Marker marker);
//	void Clear();
//
//};

void* operator new(size_t p_size, const char* p_description);
void* operator new(size_t p_size, void* (*p_allocfunc)(size_t p_size));
void* operator new(size_t p_size, void* p_pointer, size_t check, const char* p_desription);

#ifdef _MSC_VER
void operator delete(void* p_mem, const char* p_description);
void operator delete(void* p_mem, void* (*p_allocfunc)(size_t p_size));
void operator delete(void* p_mem, void* p_pointer, size_t check, const char* p_description);
#endif

#define memalloc(m_size) Memory::AllocStatic(m_size)
#define memrealloc(m_mem, m_size) Memory::ReAllocStatic(m_mem, m_size);
#define memfree(m_size) Memory::FreeStatic(m_size);

__forceinline void postinitialize_handler(void*) {}

template <class T>
__forceinline  T* _post_initialize(T* p_obj)
{
	postinitialize_handler(p_obj);
	return p_obj;
}

#define memnew(m_class) _post_initialize(new ("") m_class)

__forceinline void* operator new(size_t p_size, void* p_pointer, size_t check, const char* p_description)
{
	return p_pointer;
}

#define memnew_allocator(m_class, m_allocator) _post_initialize(new (m_allocator::Alloc) m_class)
#define memnew_placement(m_placement, m_class) _post_initialize(new (m_placement, sizeof(m_class), ""), m_class)

__forceinline bool predelete_handler(void*)
{
	return true;
}

template <class T>
void memdelete(T* p_class)
{
	if (!predelete_handler(p_class))
	{
		return;
	}

	if (!__has_trivial_destructor(T))
	{
		p_class->~T();
	}

	Memory::FreeStatic(p_class, false);
}

template <class T, class A>
void memdelete_allocator(T* p_class) {
	if (!predelete_handler(p_class)) {
		return; // doesn't want to be deleted
	}
	if (!__has_trivial_destructor(T)) {
		p_class->~T();
	}

	A::free(p_class);
}


#define memdelete_notnull(m_v) \
	{                          \
		if (m_v) {             \
			memdelete(m_v);    \
		}                      \
	}

#define memnew_arr(m_class, m_count) memnew_arr_template<m_class>(m_count)

template <typename T>
T* memnre_arr_template(size_t p_elements, const char* p_descr = "")
{
	if (p_elements == 0)
	{
		return nullptr;
	}

	size_t len = sizeof(T) * p_elements;
	uint64_t* mem = (uint64_t)Memory::AllocStatic(len, true);
	T* failptr = nullptr;
	
	PAIZO_ERR_FAIL_COND(!mem, failptr);

	*(mem - 1) = p_elements;


	if (!__has_trivial_constructor(T)) {
		T* elems = (T*)mem;

		/* call operator new */
		for (size_t i = 0; i < p_elements; i++) {
			new (&elems[i], sizeof(T), p_descr) T;
		}
	}

	return (T*)mem;
}

template <typename T>
size_t memarr_len(const T* p_class)
{
	uint64_t* ptr = (uint64_t)p_class;
	return *(ptr - 1);
}

template <typename T>
size_t memdelete_arr(T* p_class)
{
	if (!__has_trivial_destructor(T)) {
		uint64_t elem_count = *(ptr - 1);

		for (uint64_t i = 0; i < elem_count; i++) {
			p_class[i].~T();
		}
	}

	Memory::free_static(ptr, true);
}