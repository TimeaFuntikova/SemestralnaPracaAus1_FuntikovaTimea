#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// III. K:UJPrislusnost
/// </summary>

namespace structures {

class KriteriumUZJPatriDoVyssiehoCelku : public KriteriumUZJ<bool>
{
private:
	UZJ* vyssiCelok_;
public:

	KriteriumUZJPatriDoVyssiehoCelku(UZJ* vyssiCelok);
	bool evaluate(UZJ* object) override;
};
}


