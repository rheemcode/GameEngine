#include "pzpch.h"
#include "Reference.h"

bool Reference::InitRef()
{
	if (MakeReference())
	{
		if (IsReferenced() && refCountInit.UnRef())

		{
			Unreference();
		}

		return true;
	}
	else return false;
}

int Reference::ReferenceGetCount() const
{
	return refCount.Get();
}

bool Reference::MakeReference()
{
	uint32_t rcVal = refCount.RefVal();
	bool success = rcVal != 0;
	
	return success;
}

bool Reference::Unreference()
{
	uint32_t rc_val = refCount.UnrefVal();
	bool die = rc_val == 0;
	return die;
}

Reference::Reference() : Object() 
{
	refCount.Init();
	refCountInit.Init();
}