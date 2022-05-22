#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// VII. K:UJVekPodiel
/// </summary>

namespace structures {

	class KriteriumUZJUJVekovaSkupinaPodiel : public KriteriumUZJ<double>
	{
		KriteriumUZJUJVekovaSkupinaPodiel(Vector vek, static const int pohlavie);
		double evaluate(const UZJ& object) override;
	};
}