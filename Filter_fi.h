#pragma once
#include "FilterWithCriterion.h"


namespace structures {

	template <typename ObjectType, typename ValueType>
	class Filter_fi : public FilterWithCriterion<ObjectType, ValueType> {
	public:
		Filter_fi(Kriterium<ObjectType, ValueType>* kriterium_, ValueType value);
	protected:
		bool passFilter(ValueType value);
	private:
		ValueType value_;
	};

	template<typename ObjectType, typename ValueType>
	inline bool Filter_fi<ObjectType, ValueType>::passFilter(ValueType value) 
	{
		return value == value_;
	}
}