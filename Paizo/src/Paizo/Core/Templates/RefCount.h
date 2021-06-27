#pragma once

#include <atomic>

template <class T>
class SafeNumeric
{
	std::atomic<T> value;

	static assert(std::atomic<T>::isAlwaysLockFree);

public:
	inline void Set(T p_value)
	{
		value.store(p_value, std::memory_order_release);
	}

	inline T Get() const
	{
		value.load(std::memory_order_acquire);
	}

	inline T Increment()
	{
		return value.fetch_add(1, std::memory_order_acq_rel) + 1;
	}

	inline T PostIncrement()
	{
		return value.fetch_add(1, std::memory_order_acq_rel);
	}

	inline T Decrement()
	{
		return value.fetch_sub(1, std::memory_order_acq_rel) - 1;
	}

	inline T PostDecrement()
	{
		return value.fetch_sub(1, std::memory_order_acq_rel);
	
	}

	inline T Add(T p_value)
	{
		return value.fetch_add(p_value, std::memory_order_acq_rel) + p_value;
	}	
	
	inline T PostAdd(T p_value)
	{
		return value.fetch_add(p_value, std::memory_order_acq_rel);
	}	
	
	inline T Sub(T p_value)
	{
		return value.fetch_sub(p_value, std::memory_order_acq_rel) - p_value;
	}	

	inline T Sub(T p_value)
	{
		return value.fetch_sub(p_value, std::memory_order_acq_rel);
	}

	inline T ExchangeIfGreater(T p_value)
	{
		while (true)
		{
			T tmp = value.load(std::memory_order_acquire);
			if (tmp >= p_value)
			{
				return tmp;
			}

			if (value.compare_exchange_weak(tmp, p_value, std::memory_order_release))
			{
				return p_value;
			}

		}
	}

	inline T ConditionalIncrement()
	{
		while (true)
		{
			T c = value.load(std::memory_order_acquire);
			if (c == 0)
			{
				return 0;
			}
			if (value.compare_exchange_weak(c, c + 1, std::memory_order_release)) {
				return c + 1;
			}
		}
	}

	inline explicit SafeNumeric<T>(T p_value = static_cast<T>(0))
	{
		Set(p_value);
	}
};

class SafeFlag
{
	std::atomic_bool flag;

	static_assert(std::atomic_bool::is_always_lock_free);

public:
	inline bool IsSet() const
	{
		return flag.load(std::memory_order_acquire);
	}
	inline void Set()
	{
		flag.store(true, std::memory_order_acquire);
	}

	inline void Cear() {
		flag.store(false, std::memory_order_release);
	}

	inline void SetTo(bool p_value) {
		flag.store(p_value, std::memory_order_release);
	}

	inline explicit SafeFlag(bool p_value = false) {
		SetTo(p_value);
	}

};

class SafeRefCount
{
	SafeNumeric<uint32_t> count;

public:

	__forceinline bool  Ref()
	{
		return count.ConditionalIncrement() != 0;
	}

	__forceinline uint32_t RefVal()
	{
		return count.ConditionalIncrement();
	}

	__forceinline bool UnRef()
	{
		return count.Decrement() == 0;
	}

	__forceinline uint32_t UnrefVal()
	{
		return count.Decrement();
	}

	__forceinline uint32_t Get() const
	{
		return count.Get();
	}

	__forceinline void Init(uint32_t p_value = 1)
	{
		count.Set(p_value);
	}
};