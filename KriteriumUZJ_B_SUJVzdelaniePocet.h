#pragma once
#include "KriteriumUZJ_B_S.h"

/// <summary>
/// IV. K:UJVzdelaniePocet
/// </summary>

namespace structures {
	class KriteriumUZJ_B_SUJPocetObyvatelovSoVzdelanim : public KriteriumUZJ_B_S<int>
	{
		KriteriumUZJ_B_SUJPocetObyvatelovSoVzdelanim(static const int vzdelanie);
		int evaluate(const UZJ_B_S& object) override;
	};
}