#pragma once
#include "KriteriumUZJ_B_S.h"

/// <summary>
/// VI. K:UJVekPocet
/// </summary>
namespace structures {

class KriteriumUZJ_B_SPocetObyvatelovSDanymVekomAPohlavim : public KriteriumUZJ_B_S<int>
{
	KriteriumUZJ_B_SPocetObyvatelovSDanymVekomAPohlavim(unsigned int vek, static const int pohlavie);
	int evaluate(const UZJ_B_S& object) override;
};

}
