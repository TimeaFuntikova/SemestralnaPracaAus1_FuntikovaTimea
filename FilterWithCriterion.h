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
		bool pass(const ObjectType& object);
	protected:
		bool passFilter(ValueType value);
	private:
		Kriterium<ObjectType, ValueType>* kriterium_;
	};

	template<typename ObjectType, typename ValueType>
	inline bool FilterWithCriterion<ObjectType, ValueType>::pass(const ObjectType& object)
	{
		return passFilter(kriterium_->evaluate(object));
	}
}
	
