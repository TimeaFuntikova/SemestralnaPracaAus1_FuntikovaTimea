#pragma once
#include "KriteriumUZJ_B_S.h"
#include"UzemnaJednotka.h"

/// <summary>
/// X. K:UJNadradena
/// </summary>

namespace structures {

	class KriteriumUZJ_B_SNadradenaUzemnaJednotka : public KriteriumUZJ_B_S<UzemnaJednotka>
	{
		UzemnaJednotka evaluate(const UZJ_B_S& object) override;
	};
}