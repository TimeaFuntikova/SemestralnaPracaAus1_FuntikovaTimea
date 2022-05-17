#pragma once

#include "KriteriumUZJ_B_S.h"

/// <summary>
/// I. K:Nazov
/// </summary>
namespace structures {
	class KriteriumUZJ_B_SNazov : public KriteriumUZJ_B_S<std::string>
	{
		std::string evaluate(const UZJ_B_S& object) override;
	};
}
