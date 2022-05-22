#pragma once

#include "CompositeFilter.h"


/// <summary>
/// AND FILTER
/// </summary>
namespace structures {
	template <typename ObjectType>
	class Filter_OR : public CompositeFilter<ObjectType>
	{
	public:
		virutal bool pass(const ObjectType& object) = 0;
	};



}

