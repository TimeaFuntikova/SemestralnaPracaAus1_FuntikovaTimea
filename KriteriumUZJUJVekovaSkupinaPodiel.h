#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// IX. K:UJVekovaSkupinaPodiel
/// </summary>

namespace structures {

	class KriteriumUZJUJVekovaSkupinaPodiel : public KriteriumUZJ<double>
	{
	private:
		EVS_enum evs_;
		KriteriumUZJUJVekovaSkupinaPodiel(EVS_enum evs);
		double evaluate(UZJ* object) override;
	};
}