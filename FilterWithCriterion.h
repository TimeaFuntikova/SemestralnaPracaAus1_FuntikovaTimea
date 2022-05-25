#pragma once
#include "Filter.h"
#include "Kriterium.h"


/// <summary>
/// Nakolko nie je znamy navratovy typ, kriterium v spolocnom predkovi musi byt Kriterium<ObjectType, ValueType>* -- smernik
/// potomok len otestuje získanú hodnotu
/// </summary>
namespace structures {

	template<typename ObjectType, typename ValueType>
	class FilterWithCriterion : public Filter<ObjectType>
	{
	public:
		FilterWithCriterion(Kriterium<ObjectType, ValueType>* kriterium);
		~FilterWithCriterion();
		bool pass(const ObjectType; object);

	protected:
		virtual bool passFilter(ValueType) = 0;
	private:
		Kriterium<ObjectType, ValueType>* kriterium_;
	};

	template<typename ObjectType, typename ValueType>
	inline FilterWithCriterion<ObjectType, ValueType>::FilterWithCriterion(Kriterium<ObjectType, ValueType>* kriterium)
	{
		kriterium_ = kriterium;
	}

	template<typename ObjectType, typename ValueType>
	inline FilterWithCriterion<ObjectType, ValueType>::~FilterWithCriterion()
	{
		delete kriterium_;
	}

	template<typename ObjectType, typename ValueType>
	inline bool FilterWithCriterion<ObjectType, ValueType>::pass(const ObjectType object)
	{
		return passFilter(kriterium_->evaluate(object));
	}
}
	
