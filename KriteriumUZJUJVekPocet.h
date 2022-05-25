#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// VI. K:UJVekPocet
/// </summary>
namespace structures {

class KriteriumUZJPocetObyvatelovSDanymVekomAPohlavim : public KriteriumUZJ<int>
{private:
	int vek_;
	pohlavie_enum pohl_;

	KriteriumUZJPocetObyvatelovSDanymVekomAPohlavim(int vek, pohlavie_enum pohlavie);
	int evaluate(UZJ* object) override;
};

}
