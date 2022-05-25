#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// VIII. K:UJVekovaSkupinaPocet
/// </summary>

namespace structures {


	class KriteriumUZJUJVekovaSkupinaPocet : public KriteriumUZJ<int>
	{
	private:
		EVS_enum evs_;
	public:
		KriteriumUZJUJVekovaSkupinaPocet(EVS_enum evs);
		int evaluate(UZJ* object) override;
	};
}