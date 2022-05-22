#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// VI. K:UJVekPocet
/// </summary>
namespace structures {

class KriteriumUZJPocetObyvatelovSDanymVekomAPohlavim : public KriteriumUZJ<int>
{
	KriteriumUZJPocetObyvatelovSDanymVekomAPohlavim(unsigned int vek, static const int pohlavie);
	int evaluate(const UZJ& object) override;
};

}
