#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// IV. K:UJVzdelaniePodiel
/// </summary>

namespace structures {

	class KriteriumUZJUJVzdelaniePodiel : public KriteriumUZJ<double>
	{
		KriteriumUZJUJVzdelaniePodiel(static const int vzdelanie);
		double evaluate(const UZJ& object) override;
	};
}