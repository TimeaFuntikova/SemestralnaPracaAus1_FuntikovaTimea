#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// IV. K:UJVzdelaniePodiel
/// </summary>

namespace structures {
	vzdelanie_enum vzdel_;
	class KriteriumUZJUJVzdelaniePodiel : public KriteriumUZJ<double>
	{
		KriteriumUZJUJVzdelaniePodiel(vzdelanie_enum vzdelanie);
		double evaluate(UZJ* object) override;
	};
}