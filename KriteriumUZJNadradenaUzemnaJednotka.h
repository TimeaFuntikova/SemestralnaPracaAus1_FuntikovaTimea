#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// X. K:UJNadradena
/// </summary>

namespace structures {

	class KriteriumUZJNadradenaUzemnaJednotka : public KriteriumUZJ<UZJ*>
	{
		UZJ* evaluate(UZJ* object) override;
	};
}