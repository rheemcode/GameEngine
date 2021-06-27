#pragma once
#include "Templates/RefCount.h"
#include "Object.h"
#include "Core.h"

class Reference
{
	SafeRefCount refCount;
	SafeRefCount refCountInit;

public:
	__forceinline bool IsReferenced() const { return refCountInit.Get() != 1; }
	bool InitRef();
	bool MakeReference();
	bool Unreference();
	int ReferenceGetCount() const;

	Reference();
	~Reference();
};

template <class T>
class Ref
{
	T* reference = nullptr;

	void MakeRef(const Ref& p_from)
	{
		if (p_from.reference == reference)
			return;

		UnRef();

		reference = p_from.reference;
		if (reference)
		{
			reference->MakeReference();
		}
	}

	void RefPointer(T* p_ref)
	{
		PAIZO_ASSERT(!p_ref);

		if (p_ref->InitRef())
		{
			reference = p_ref;
		}
	}

public:
	__forceinline bool operator==(const T* p_ptr) const {
		return reference == p_ptr;
	}
	__forceinline bool operator!=(const T* p_ptr) const {
		return reference != p_ptr;
	}

	__forceinline bool operator<(const Ref<T>& p_r) const {
		return reference < p_r.reference;
	}
	__forceinline bool operator==(const Ref<T>& p_r) const {
		return reference == p_r.reference;
	}
	__forceinline bool operator!=(const Ref<T>& p_r) const {
		return reference != p_r.reference;
	}

	__forceinline T* operator->() {
		return reference;
	}

	__forceinline T* operator*() {
		return reference;
	}

	__forceinline const T* operator->() const {
		return reference;
	}

	__forceinline const T* ptr() const {
		return reference;
	}
	__forceinline T* ptr() {
		return reference;
	}

	__forceinline const T* operator*() const {
		return reference;
	}

	void operator=(const Ref& p_from) {
		MakeRef(p_from);
	}

	template <class T_Other>
	void operator=(const Ref<T_Other>& p_from) {
		Reference* refb = const_cast<Reference*>(static_cast<const Reference*>(p_from.ptr()));
		if (!refb) {
			UnRef();
			return;
		}
		Ref r;
		r.reference = Object::cast_to<T>(refb);
		MakeRef(r);
		r.reference = nullptr;
	}

	template <class T_Other>
	void reference_ptr(T_Other* p_ptr) {
		if (reference == p_ptr) {
			return;
		}
		UnRef();

		T* r = Object::cast_to<T>(p_ptr);
		if (r) {
			ref_pointer(r);
		}
	}

	Ref(const Ref& p_from) {
		MakeRef(p_from);
	}

	template <class T_Other>
	Ref(const Ref<T_Other>& p_from) {
		Reference* refb = const_cast<Reference*>(static_cast<const Reference*>(p_from.ptr()));
		if (!refb) {
			UnRef();
			return;
		}
		Ref r;
		r.reference = Object::cast_to<T>(refb);
		MakeRef(r);
		r.reference = nullptr;
	}

	Ref(T* p_reference) {
		if (p_reference) {
			ref_pointer(p_reference);
		}
	}

	inline bool is_valid() const { return reference != nullptr; }
	inline bool is_null() const { return reference == nullptr; }

	void UnRef() {
		if (reference && reference->UnReference()) {
			memdelete(reference);
		}
		reference = nullptr;
	}

	void Instance() {
		MakeRef(memnew(T));
	}

	Ref() {}

	~Ref() {
		UnRef();
	}
};

class WeakRef : public Reference
{
public:
	void SetObj(Object* p_object);
	void SetRef(const Ref<Reference>& p_ref);

	WeakRef() {}
};

template <class T>
struct PtrToArg {
	__forceinline static Ref<T> convert(const void* p_ptr) {
		return Ref<T>(const_cast<T*>(reinterpret_cast<const T*>(p_ptr)));
	}

	__forceinline static void encode(Ref<T> p_val, const void* p_ptr) {
		*(Ref<Reference> *)p_ptr = p_val;
	}
};

template <class T>
struct PtrToArg<const Ref<T>&> {
	__forceinline static Ref<T> convert(const void* p_ptr) {
		return Ref<T>((T*)p_ptr);
	}
};