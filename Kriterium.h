#pragma once


//v impl. prirucke zodpoveda prikladu Criterion<ObjectType, ResultType>
//nevytvara ani atributy ani meody

namespace structures {
	template <typename ObjectType, typename ResultType>
	class Kriterium   
	{
	public:
		virtual ResultType evaluate(const ObjectType& object)  = 0;
	};
}
