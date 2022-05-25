#pragma once

#include "CompositeFilter.h"


/// <summary>
/// OR FILTER ak objekt presiel aspon jednym filtrom vrati sa true
/// </summary>
namespace structures {

	template <typename ObjectType>
	class Filter_OR : public CompositeFilter<ObjectType>
	{
		bool pass(ObjectType& object) override;
	};

	template<typename ObjectType>
	inline bool Filter_OR<ObjectType>::pass(ObjectType& object)
	{
		bool pom = false;

		for (Filter<ObjectType>* filter : *filtre_)
		{
			if (filter->pass(object)) {
				pom = true;
			}
		}
		return pom;
	}
}

