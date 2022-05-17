#pragma once
#include "KriteriumUZJ_B_S.h"

/// <summary>
/// III. K:UJPrislusnost
/// </summary>

namespace structures {

class KriteriumUZJ_B_SPatriDoVyssiehoCelku : public KriteriumUZJ_B_S<bool>
{
	KriteriumUZJ_B_SPatriDoVyssiehoCelku(int vyssiCelok);
	bool evaluate(const UZJ_B_S& object) override;
};
}


