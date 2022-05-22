#pragma once

#include "KriteriumUZJ.h"

/// <summary>
/// I. K:Nazov
/// </summary>
namespace structures {
	class KriteriumUZJNazov : public KriteriumUZJ<std::string>
	{
		std::string evaluate(const UZJ& object) override;
	};
}
