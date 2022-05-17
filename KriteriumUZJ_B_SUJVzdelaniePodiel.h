#pragma once
#include "KriteriumUZJ_B_S.h"

/// <summary>
/// IV. K:UJVzdelaniePodiel
/// </summary>

namespace structures {

	class KriteriumUZJ_B_SUJVzdelaniePodiel : public KriteriumUZJ_B_S<double>
	{
		KriteriumUZJ_B_SUJVzdelaniePodiel(static const int vzdelanie);
		double evaluate(const UZJ_B_S& object) override;
	};
}