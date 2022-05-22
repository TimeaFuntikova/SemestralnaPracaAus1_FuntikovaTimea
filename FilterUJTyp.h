#pragma once
#include "Filter_fi.h"
#include "UZJ.h"


/// <summary>
/// 2. Filter pre UJ typ
/// </summary>
namespace structures {
	template <typename ObjectType, typename ValueType>
	class FilterUJTyp : public Filter_fi<UZJ, std::string>
	{
	public:
		FilterUJTyp();
	protected:
		bool passFilter(ValueType value);
	private:
		ValueType value_;

	};

}