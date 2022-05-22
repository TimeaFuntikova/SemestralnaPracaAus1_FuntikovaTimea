#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// IX. K:UJVekovaSkupinaPodiel
/// </summary>

namespace structures {

	class KriteriumUZJUJVekovaSkupinaPodiel : public KriteriumUZJ<double>
	{
		KriteriumUZJUJVekovaSkupinaPodiel(static const int vekovaSkupina);
		double evaluate(const UZJ& object) override;
	};
}