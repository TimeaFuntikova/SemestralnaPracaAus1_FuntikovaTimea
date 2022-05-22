#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// IV. K:UJVzdelaniePocet
/// </summary>

namespace structures {
	class KriteriumUZJUJPocetObyvatelovSoVzdelanim : public KriteriumUZJ<int>
	{
		KriteriumUZJUJPocetObyvatelovSoVzdelanim(static const int vzdelanie);
		int evaluate(const UZJ& object) override;
	};
}