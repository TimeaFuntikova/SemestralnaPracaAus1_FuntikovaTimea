#pragma once

#include "Enums.h"

#include "Array.h"
//#include "ArrayList.h"

class Vzdelanie
{
private:

	vzdelanie_enum vzdelanieEnum_;
	structures::Array<int>* vzdelanieSK_;


/*	structures::ArrayList<vzdelanie_enum>* bezUkVzd_;
	structures::ArrayList<vzdelanie_enum>* zakl_;
	structures::ArrayList<vzdelanie_enum>* ucn_;
	structures::ArrayList<vzdelanie_enum>* str_;
	structures::ArrayList<vzdelanie_enum>* vyss_;
	structures::ArrayList<vzdelanie_enum>* vysok_;
	structures::ArrayList<vzdelanie_enum>* bezVzd_;
	structures::ArrayList<vzdelanie_enum>* unkn_;
	*/

public:
	Vzdelanie() {

		vzdelanieSK_ = new structures::Array<int>(8);
		

		/*
		bezUkVzd_ = new structures::ArrayList<vzdelanie_enum>();
		zakl_ = new structures::ArrayList<vzdelanie_enum>();
		ucn_ = new structures::ArrayList<vzdelanie_enum>();
		str_ = new structures::ArrayList<vzdelanie_enum>();
		vyss_ = new structures::ArrayList<vzdelanie_enum>();
		vysok_ = new structures::ArrayList<vzdelanie_enum>();
		bezVzd_ = new structures::ArrayList<vzdelanie_enum>();
		unkn_ = new structures::ArrayList<vzdelanie_enum>();
		*/
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
		delete bezUkVzd_;
		delete zakl_;
		delete ucn_;
		delete str_;
		delete vyss_;
		delete vysok_;
		delete bezVzd_;
		delete unkn_;

		bezUkVzd_ = nullptr;
		zakl_ = nullptr;
		ucn_ = nullptr;
		str_ = nullptr;
		vyss_ = nullptr;
		vysok_ = nullptr;
		bezVzd_ = nullptr;
		unkn_ = nullptr;
		*/

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

	/*
	int getVzdelaniePocet(vzdelanie_enum(vzdel)) {
		
		 //transformujVzdelanieInt();
		if (vzdel == vzdelanie_enum(0))
		{
			return bezUkVzd_->size();
		}

		if (vzdel == vzdelanie_enum(1))
		{
			return zakl_->size();
		}

		if (vzdel == vzdelanie_enum(2))
		{
			return ucn_->size();
		}

		if (vzdel == vzdelanie_enum(3))
		{
			return str_->size();
		}

		if (vzdel == vzdelanie_enum(4))
		{
			return vyss_->size();
		}

		if (vzdel == vzdelanie_enum(5))
		{
			return vysok_->size();
		}

		if (vzdel == vzdelanie_enum(6))
		{
			return bezVzd_->size();
		}

		if (vzdel == vzdelanie_enum(7))
		{
			return unkn_->size();
		}

		else {
			throw std::logic_error("getVzdelaniePocet(vzdelanie_enum(vzdel)) : number is not 0-7. sth went wrong");
		}
	}*/


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

	/*
	int celkovyPocetLudiSoVzdelanimALL() {
		int suma = (celkovyPocetLudiSoVzdelanim() + bezVzd_->size() + unkn_->size());
		return suma;
	}

	int celkovyPocetLudiSoVzdelanim() {
		int suma = (bezUkVzd_->size() +
			zakl_->size() +
			ucn_->size() +
			str_->size() +
			vyss_->size() +
			vysok_->size());
		return suma;
	}
	*/
};

