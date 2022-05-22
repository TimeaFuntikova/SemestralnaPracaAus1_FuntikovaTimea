#pragma once
#include "FilterWithCriterion.h"


namespace structures {

	template <typename ObjectType, typename ValueType>
	class Filter_Fl : public FilterWithCriterion<ObjectType, ValueType> {
	public:
		Filter_Fl(Kriterium<ObjectType, ValueType>*, Valuetype value);
	protected:
		bool passFilter(ValueType value);
	private:
		ValueType valueMax_;
		ValueType valueMin_;
	};

	template<typename ObjectType, typename ValueType>
	inline bool Filter_Fl<ObjectType, ValueType>::passFilter(ValueType value) 
	{
		return value >= valueMin_ && value <= valueMax_;
	}
}
