#pragma once
#include "Filter_fi.h"
#include "UZJ.h"
#include "KriteriumUZJNazov.h"


/// <summary>
/// 1. Filter pre názov, vracia hodnotu
/// </summary>
namespace structures {
	template <typename ObjectType, typename ValueType>
	class FilterUJNazov : public Filter_fi<UZJ, std::string>
	{
	public: 
		FilterUJNazov(std::string nazov) : Filter_fi(new KriteriumUZJNazov(), nazov) {}
	};

}