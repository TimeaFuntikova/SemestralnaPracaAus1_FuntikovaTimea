#pragma once
#include "Filter.h"

/// <summary>
/// Kompozitny filter pre zhodnotenie AND a OR
/// </summary>
namespace structures {

	template <typename ObjectType>
	class CompositeFilter : Filter<ObjectType>
	{
	public:
		virtual void registerFilter(Filter<ObjectType>* filter) const = 0;
	protected:
		//VLASTNA US<Filter<ObjectType>*> filters_;
	};
}

