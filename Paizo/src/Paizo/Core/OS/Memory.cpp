#include "pzpch.h"

#include "Memory.h"

void* operator new(size_t p_size, const char* p_description)
{
	return Memory::AllocStatic(p_size, false);
}

void* operator new(size_t p_size, void* (*p_allocfunc)(size_t p_size))
{
	return p_allocfunc(p_size);
}

#ifdef _MSC_VER
void operator delete(void* p_mem, const char* p_description)
{
	PAIZO_CRASH_MSG("Call to placement delete should'nt happen");
}

void operator delete(void* p_mem, void* (*p_allocfunc)(size_t p_size)) {
	PAIZO_CRASH_MSG("Call to placement delete should not happen.");
}

void operator delete(void* p_mem, void* p_pointer, size_t check, const char* p_description) {
	PAIZO_CRASH_MSG("Call to placement delete should not happen.");
}
#endif // _MSC_VER

#ifdef DEBUG_ENABLED
SafeNumeric<uint64_t> Memory::memUsage;
SafeNumeric<uint64_t> Memory::maxUsage;
#endif


SafeNumeric<uint64_t> Memory::allocCount;

void* Memory::AllocStatic(size_t p_bytes, bool p_pad_align)
{
#ifdef DEBUG_ENABLED
	bool prepad = true;
#else
	bool prepad = false;
#endif

	void* mem = malloc(p_bytes + (prepad ? PAD_ALIGN : 0));

	PAIZO_ERR_FAIL_COND(!mem, nullptr);

	allocCount.Increment();

	if (prepad)
	{
		uint64_t* s = (uint64_t*)mem;
		*s = p_bytes;

		uint8_t* s8 = (uint8_t*)mem;
#ifdef DEBUG_ENABLED
		uint64_t newMemUsage = memUsage.Add(p_bytes);
		maxUsage.ExchangeIfGreater(newMemUsage);
#endif

		return s8 + PAD_ALIGN;
	}
	else
	{
		return mem;
	}

}


void* Memory::ReAllocStatic(void* p_memory, size_t p_bytes, bool p_pad_align) {
	if (p_memory == nullptr) {
		return AllocStatic(p_bytes, p_pad_align);
	}

	uint8_t* mem = (uint8_t*)p_memory;

#ifdef DEBUG_ENABLED
	bool prepad = true;
#else
	bool prepad = p_pad_align;
#endif

	if (prepad) {
		mem -= PAD_ALIGN;
		uint64_t* s = (uint64_t*)mem;

#ifdef DEBUG_ENABLED
		if (p_bytes > *s) {
			uint64_t new_mem_usage = memUsage.Add(p_bytes - *s);
			maxUsage.ExchangeIfGreater(new_mem_usage);
		}
		else {
			memUsage.Sub(*s - p_bytes);
		}
#endif

		if (p_bytes == 0) {
			free(mem);
			return nullptr;
		}
		else {
			*s = p_bytes;

			mem = (uint8_t*)realloc(mem, p_bytes + PAD_ALIGN);
			PAIZO_ERR_FAIL_COND(!mem, nullptr);

			s = (uint64_t*)mem;

			*s = p_bytes;

			return mem + PAD_ALIGN;
		}
	}
	else {
		mem = (uint8_t*)realloc(mem, p_bytes);

		PAIZO_ERR_FAIL_COND(mem == nullptr && p_bytes > 0, nullptr);

		return mem;
	}
}


void Memory::FreeStatic(void* p_ptr, bool  p_padAlign)
{
	PAIZO_ERR_FAIL_COND_N(p_ptr == nullptr);
	uint8_t* mem = (uint8_t*)p_ptr;

#ifdef DEBUG_ENABLED
	bool prepad = true;
#else
	bool prepad = p_pad_align;
#endif

	allocCount.Decrement();

	if (prepad)
	{
		mem -= PAD_ALIGN;

#ifdef DEBUG_ENABLED
		uint64_t* s = (uint64_t*)mem;
		memUsage.Sub(*s);
#endif
		free(mem);
	} 
	else
	{
		free(mem);
	}
}

uint64_t Memory::GetAvailableMem() 
{
	return -1; 
}

uint64_t Memory::GetMemUsage() {
#ifdef DEBUG_ENABLED
	return memUsage.Get();
#else
	return 0;
#endif
}

uint64_t Memory::GetMaxMemUsage() {
#ifdef DEBUG_ENABLED
	return maxUsage.Get();
#else
	return 0;
#endif
}
