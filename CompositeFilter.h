#pragma once
#include "Filter.h"

#include "ArrayList.h"

/// <summary>
/// Kompozitny filter pre zhodnotenie AND a OR
/// </summary>
namespace structures {

	template <typename ObjectType>
	class CompositeFilter : Filter<ObjectType>
	{
	public:
		CompositeFilter() {
			filtre_ = new structures::ArrayList<Filter<ObjectType>*>();
		}

			~CompositeFilter() {
				delete filtre_;
			}

			void registerFilter(Filter<ObjectType>* filter)
			{
				filtre_->add(filter);
			}
		protected:
			//VLASTNA US<Filter<ObjectType>*> filtre_;

			structures::ArrayList<Filter<ObjectType>*>* filtre_;

	};
}

