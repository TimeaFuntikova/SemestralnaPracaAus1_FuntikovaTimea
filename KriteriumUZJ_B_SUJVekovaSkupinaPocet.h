#pragma once
#include "KriteriumUZJ_B_S.h"

/// <summary>
/// VIII. K:UJVekovaSkupinaPocet
/// </summary>

namespace structures {

	class KriteriumUZJ_B_SUJVekovaSkupinaPodiel : public KriteriumUZJ_B_S<int>
	{
		KriteriumUZJ_B_SUJVekovaSkupinaPodiel(static const int vekovaSkupina);
		int evaluate(const UZJ_B_S& object) override;
	};
}