#pragma once
#include "FilterWithCriterion.h"


namespace structures {

	template <typename ObjectType, typename ValueType>
	class Filter_fi : public FilterWithCriterion<ObjectType, ValueType> {
	public:
		Filter_fi(Kriterium<ObjectType, ValueType>* kriterium_, ValueType value);
		virtual ~Filter_fi() = default;
	protected:
		bool passFilter(ValueType value) override;
	private:
		ValueType value_;
	};

	template<typename ObjectType, typename ValueType>
	inline Filter_fi<ObjectType, ValueType>::Filter_fi(Kriterium<ObjectType, ValueType>* kriterium_, ValueType value)
	{
		value_ = value;
	}

	template<typename ObjectType, typename ValueType>
	inline bool Filter_fi<ObjectType, ValueType>::passFilter(ValueType value) 
	{
		return value == value_ ? true : false;
	}
}