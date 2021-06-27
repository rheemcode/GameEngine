#pragma once


class Object
{
public:
	template <class T>
	static T* CastTo(Object* p_object)
	{
		return dynamic_cast<T*>(p_object);
	}	
	template <class T>
	static const  T* CastTo(Object* p_object)
	{
		return dynamic_cast<const T*>(p_object);
	}

	Object(){}
	virtual ~Object();
};