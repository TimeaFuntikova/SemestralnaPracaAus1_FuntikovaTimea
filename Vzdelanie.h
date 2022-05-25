#pragma once

#include "Enums.h"

#include "Array.h"
//#include "ArrayList.h"

class Vzdelanie
{
private:

	vzdelanie_enum vzdelanieEnum_;
	structures::Array<int>* vzdelanieSK_;

public:
	Vzdelanie() {

		vzdelanieSK_ = new structures::Array<int>(8);
	}

	~Vzdelanie() 
	{
		this->clearVzdelanie();
		delete vzdelanieSK_;
		vzdelanieSK_ = nullptr;

	}
		void clearVzdelanie() 
		{
			for (int i = 0; i < vzdelanieSK_->size(); i++)
			{
				vzdelanieSK_->at(i) = 0;
			}
		}
	

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

	void priradDoVzdelania(vzdelanie_enum vzdel) 
	{
		switch (vzdel) {
		case vzdelanie_enum::BEZ_UKONCENEHO_VZDELANIA: vzdelanieSK_->at(0) += 1; break;
		case vzdelanie_enum::ZAKLADNE: vzdelanieSK_->at(1) += 1; break;
		case vzdelanie_enum::UCNOVSKE: vzdelanieSK_->at(2) += 1; break;
		case vzdelanie_enum::STREDNE: vzdelanieSK_->at(3) += 1; break;
		case vzdelanie_enum::VYSSIE: vzdelanieSK_->at(4) += 1; break;
		case vzdelanie_enum::VYSOKOSKOLSKE: vzdelanieSK_->at(5) += 1; break;
		case vzdelanie_enum::BEZ_VZDELANIA: vzdelanieSK_->at(6) += 1; break;
		case vzdelanie_enum::NEZISTENE: vzdelanieSK_->at(7) += 1; break;
		}
	}
	int getVzdelaniePocet(vzdelanie_enum(vzdel)) //pre konkretnu kategoriu
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
		}
	}

	


	int celkovyPocetLudiSoVzdelanim() {
		int pom = 0;
		for (int i = 0; i < 5; i++)
		{
			pom += vzdelanieSK_->at(i);
		}
		return pom;
	}

	int celkovyPocetLudiSoVzdelanimALL() {
		int pom = 0;
		pom = celkovyPocetLudiSoVzdelanim();
		for (int i = 5; i < 7; i++)
		{
			pom += vzdelanieSK_->at(i);
		}
		return pom;
	}
};

