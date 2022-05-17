#pragma once
#include "KriteriumUZJ_B_S.h"

/// <summary>
/// IX. K:UJVekovaSkupinaPodiel
/// </summary>

namespace structures {

	class KriteriumUZJ_B_SUJVekovaSkupinaPodiel : public KriteriumUZJ_B_S<double>
	{
		KriteriumUZJ_B_SUJVekovaSkupinaPodiel(static const int vekovaSkupina);
		double evaluate(const UZJ_B_S& object) override;
	};
}