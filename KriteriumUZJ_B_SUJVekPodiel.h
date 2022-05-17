#pragma once
#include "KriteriumUZJ_B_S.h"

/// <summary>
/// VII. K:UJVekPodiel
/// </summary>

namespace structures {

	class KriteriumUZJ_B_SUJVekovaSkupinaPodiel : public KriteriumUZJ_B_S<double>
	{
		KriteriumUZJ_B_SUJVekovaSkupinaPodiel(Vector vek, static const int pohlavie);
		double evaluate(const UZJ_B_S& object) override;
	};
}