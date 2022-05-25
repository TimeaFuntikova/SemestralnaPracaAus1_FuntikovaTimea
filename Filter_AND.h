#pragma once
#include "CompositeFilter.h"

/// <summary>
/// AND FILTER
/// </summary>
namespace structures {
	template <typename ObjectType>
	class Filter_AND : public CompositeFilter<ObjectType>
	{
	public:
		bool pass(ObjectType object) override;
	};


	template<typename ObjectType>
	inline bool Filter_AND<ObjectType>::pass(ObjectType object)
	{

		for (Filter<ObjectType>* filter : *CompositeFilter::filtre_)
		{
			if (!filter->pass(object)) {
				return false;
			}
		}
		return true;
	}
}

