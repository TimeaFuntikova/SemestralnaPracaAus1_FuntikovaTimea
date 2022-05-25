#pragma once

/// <summary>
/// SPOLOCNY VIRTUALNY PREDOK, v impl. prirucke zodpoveda prikladu Filter<ObjectType>
/// nevytvara ani atributy ani metody
/// tento predok preberie testovany objekt a v abstratktnej metode urci, ci filtrom presiel
/// </summary>
namespace structures {
	template <typename ObjectType>
	class Filter
	{
	public:
		virtual bool pass(ObjectType object) = 0;
		~Filter() = default;

	};
}

