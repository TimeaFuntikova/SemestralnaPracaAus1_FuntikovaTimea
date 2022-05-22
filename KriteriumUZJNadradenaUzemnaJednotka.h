#pragma once
#include "KriteriumUZJ.h"
#include "UZJ.h"

/// <summary>
/// X. K:UJNadradena
/// </summary>

namespace structures {

	class KriteriumUZJNadradenaUzemnaJednotka : public KriteriumUZJ<UZJ>
	{
		UZJ evaluate(const UZJ& object) override;
	};
}