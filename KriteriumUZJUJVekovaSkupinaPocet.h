#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// VIII. K:UJVekovaSkupinaPocet
/// </summary>

namespace structures {

	class KriteriumUZJUJVekovaSkupinaPodiel : public KriteriumUZJ<int>
	{
		KriteriumUZJUJVekovaSkupinaPodiel(static const int vekovaSkupina);
		int evaluate(const UZJ& object) override;
	};
}