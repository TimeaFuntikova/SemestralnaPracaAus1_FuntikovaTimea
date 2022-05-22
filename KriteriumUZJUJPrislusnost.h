#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// III. K:UJPrislusnost
/// </summary>

namespace structures {

class KriteriumUZJPatriDoVyssiehoCelku : public KriteriumUZJ<bool>
{
	KriteriumUZJPatriDoVyssiehoCelku(int vyssiCelok);
	bool evaluate(const UZJ& object) override;
};
}


