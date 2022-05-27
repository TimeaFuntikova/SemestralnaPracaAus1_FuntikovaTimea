#include "Vzdelanie.h"

namespace structures {

	Vzdelanie::Vzdelanie() {
		vzdelanieSK_ = new structures::Array<int>(8);
		vzdelanieEnum_ = vzdelanie_enum::NEZISTENE;
	}

	Vzdelanie::~Vzdelanie() {
		this->clearVzdelanie();
		delete vzdelanieSK_;
		vzdelanieSK_ = nullptr;
	}

	void Vzdelanie::clearVzdelanie()
	{
		for (int i = 0; i < vzdelanieSK_->size(); i++)
		{
			vzdelanieSK_->at(i) = 0;
		}
	}

	void Vzdelanie::priradDoVzdelania(vzdelanie_enum vzdel, int pocetLudiSDanymVzdelanim)
	{
		switch (vzdel) {
		case vzdelanie_enum::BEZ_UKONCENEHO_VZDELANIA: vzdelanieSK_->at(0) += pocetLudiSDanymVzdelanim; break;
		case vzdelanie_enum::ZAKLADNE: vzdelanieSK_->at(1) += pocetLudiSDanymVzdelanim; break;
		case vzdelanie_enum::UCNOVSKE: vzdelanieSK_->at(2) += pocetLudiSDanymVzdelanim; break;
		case vzdelanie_enum::STREDNE: vzdelanieSK_->at(3) += pocetLudiSDanymVzdelanim; break;
		case vzdelanie_enum::VYSSIE: vzdelanieSK_->at(4) += pocetLudiSDanymVzdelanim; break;
		case vzdelanie_enum::VYSOKOSKOLSKE: vzdelanieSK_->at(5) += pocetLudiSDanymVzdelanim; break;
		case vzdelanie_enum::BEZ_VZDELANIA: vzdelanieSK_->at(6) += pocetLudiSDanymVzdelanim; break;
		case vzdelanie_enum::NEZISTENE: vzdelanieSK_->at(7) += pocetLudiSDanymVzdelanim; break;
		}
	}

	int Vzdelanie::getVzdelaniePocet(vzdelanie_enum(vzdel)) //pre konkretnu kategoriu
	{
		switch (vzdel) {
		case vzdelanie_enum::BEZ_UKONCENEHO_VZDELANIA: vzdelanieSK_->at(0); break;
		case vzdelanie_enum::ZAKLADNE: vzdelanieSK_->at(1); break;
		case vzdelanie_enum::UCNOVSKE: vzdelanieSK_->at(2); break;
		case vzdelanie_enum::STREDNE: vzdelanieSK_->at(3); break;
		case vzdelanie_enum::VYSSIE: vzdelanieSK_->at(4); break;
		case vzdelanie_enum::VYSOKOSKOLSKE: vzdelanieSK_->at(5); break;
		case vzdelanie_enum::BEZ_VZDELANIA: vzdelanieSK_->at(6); break;
		case vzdelanie_enum::NEZISTENE: vzdelanieSK_->at(7); break;
		default:
			return -1; //keď sa toto zaráta do zozb dát -> neda sa odhalit pripadna chyba...
			break;
		}
	}

	void Vzdelanie::navysCelkovyPocetVzdelania(Vzdelanie* vzd) 
	{
		vzdelanieSK_->at(0) += getVzdelaniePocet(vzdelanie_enum::BEZ_UKONCENEHO_VZDELANIA);
		vzdelanieSK_->at(1) += getVzdelaniePocet(vzdelanie_enum::ZAKLADNE);
		vzdelanieSK_->at(2) += getVzdelaniePocet(vzdelanie_enum::UCNOVSKE);
		vzdelanieSK_->at(3) += getVzdelaniePocet(vzdelanie_enum::STREDNE);
		vzdelanieSK_->at(4) += getVzdelaniePocet(vzdelanie_enum::VYSSIE);
		vzdelanieSK_->at(5) += getVzdelaniePocet(vzdelanie_enum::VYSOKOSKOLSKE);
		vzdelanieSK_->at(6) += getVzdelaniePocet(vzdelanie_enum::BEZ_VZDELANIA);
		vzdelanieSK_->at(7) += getVzdelaniePocet(vzdelanie_enum::NEZISTENE);
	}

	void Vzdelanie::setPocetVzdelanie(vzdelanie_enum vzd, int pocet) {

		switch (vzd) {

		case vzdelanie_enum::BEZ_UKONCENEHO_VZDELANIA:
			vzdelanieSK_->at(0) = pocet;
			break;
		case vzdelanie_enum::ZAKLADNE:
			vzdelanieSK_->at(1) = pocet;
			break;
		case vzdelanie_enum::UCNOVSKE:
			vzdelanieSK_->at(2) = pocet;
			break;
		case vzdelanie_enum::STREDNE:
			vzdelanieSK_->at(3) = pocet;
			break;
		case vzdelanie_enum::VYSSIE:
			vzdelanieSK_->at(4) = pocet;
			break;
		case vzdelanie_enum::VYSOKOSKOLSKE:
			vzdelanieSK_->at(5) = pocet;
			break;
		case vzdelanie_enum::BEZ_VZDELANIA:
			vzdelanieSK_->at(6) = pocet;
			break;
		case vzdelanie_enum::NEZISTENE:
			vzdelanieSK_->at(7) = pocet;
			break;
		default:
			break;;
		}
	}

	int Vzdelanie::celkovyPocetLudiSoVzdelanim() {
		int pom = 0;
		for (int i = 0; i < 5; i++)
		{
			pom += vzdelanieSK_->at(i);
		}
		return pom;
	}

	int Vzdelanie::celkovyPocetLudiSoVzdelanimALL() {
		int pom = 0;
		pom = celkovyPocetLudiSoVzdelanim();
		for (int i = 5; i < 7; i++)
		{
			pom += vzdelanieSK_->at(i);
		}
		return pom;
	}
}
