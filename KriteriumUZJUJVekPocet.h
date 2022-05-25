#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// VI. K:UJVekPocet
/// </summary>
namespace structures {

class KriteriumUZJPocetObyvatelovSDanymVekomAPohlavim : public KriteriumUZJ<int>
{
private:
	int vek_;
	pohlavie_enum pohl_;

	KriteriumUZJPocetObyvatelovSDanymVekomAPohlavim(pohlavie_enum pohlavie, int vek) :
		pohl_(pohlavie), vek_(vek) {}
	int evaluate(UZJ* object) override;
};

}
