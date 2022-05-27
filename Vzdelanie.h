#pragma once

#include "Enums.h"
#include "Array.h"

namespace structures {
	class Vzdelanie
	{
	private:
		vzdelanie_enum vzdelanieEnum_;
		Array<int>* vzdelanieSK_;
	public:
		Vzdelanie(); 
		~Vzdelanie();
		void clearVzdelanie();
		void priradDoVzdelania(vzdelanie_enum vzdel, int pocetLudiSDanymVzdelanim);
		int getVzdelaniePocet(vzdelanie_enum(vzdel));
		int celkovyPocetLudiSoVzdelanim();
		int celkovyPocetLudiSoVzdelanimALL();
		void navysCelkovyPocetVzdelania(Vzdelanie* vzd);
		void setPocetVzdelanie(vzdelanie_enum vzd, int pocet);
		/*
		const int& transformujVzdelanieInt() const
		{
			switch (vzdelanieEnum_) {
			case vzdelanie_enum::BEZ_UKONCENEHO_VZDELANIA: return 0; break;
			case vzdelanie_enum::ZAKLADNE: return 1; break;
			case vzdelanie_enum::UCNOVSKE: return 2; break;
			case vzdelanie_enum::STREDNE: return 3; break;
			case vzdelanie_enum::VYSSIE: return 4; break;
			case vzdelanie_enum::VYSOKOSKOLSKE: return 5; break;
			case vzdelanie_enum::BEZ_VZDELANIA: return 6; break;
			case vzdelanie_enum::NEZISTENE: return 7; break;
			}
		}
		//USELESS AF _ THIS SHOULD WORK ANYWAY
		*/
	};
}

