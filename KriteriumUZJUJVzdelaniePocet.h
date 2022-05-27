#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// IV. K:UJVzdelaniePocet
/// </summary>

namespace structures {
	class KriteriumUZJUJPocetObyvatelovSoVzdelanim : public KriteriumUZJ<int>
	{
	private:
		vzdelanie_enum vzdel_;
	public:
		KriteriumUZJUJPocetObyvatelovSoVzdelanim(vzdelanie_enum vzdelanie);
		int evaluate(UZJ* object) override;
	};
}