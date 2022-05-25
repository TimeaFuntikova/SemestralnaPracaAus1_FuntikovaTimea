#pragma once
#include "FilterWithCriterion.h"


namespace structures {

	template <typename ObjectType, typename ValueType>
	class Filter_Fl : public FilterWithCriterion<ObjectType, ValueType> {
	public:
		Filter_Fl(Kriterium<ObjectType, ValueType>*, ValueType min, ValueType max);
	protected:
		bool passFilter(ValueType value);
	private:
		ValueType valueMax_;
		ValueType valueMin_;
	};

	template<typename ObjectType, typename ValueType>
	inline Filter_Fl<ObjectType, ValueType>::Filter_Fl(Kriterium<ObjectType, ValueType>*, ValueType min, ValueType max)
	{
		valueMin_ = min;
		valueMax_ = max;
	}

	template<typename ObjectType, typename ValueType>
	inline bool Filter_Fl<ObjectType, ValueType>::passFilter(ValueType value) 
	{
		return value >= valueMin_ && value <= valueMax_;
	}
}
