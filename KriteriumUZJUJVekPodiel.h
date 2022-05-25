#pragma once
#include "KriteriumUZJ.h"

/// <summary>
/// VII. K:UJVekPodiel
/// </summary>

namespace structures {

	class KriteriumUZJUJVekPodiel : public KriteriumUZJ<double>
	{
	private:
		pohlavie_enum pohl_;
		int vek_;
	public:
		KriteriumUZJUJVekPodiel(int vek, pohlavie_enum pohlavie);
		double evaluate(UZJ* object) override;
	};
}