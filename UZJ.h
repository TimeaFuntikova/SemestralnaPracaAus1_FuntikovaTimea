#pragma once

#include "Structure.h"
#include "Types.h"
#include "Utils.h"
#include "Vector.h" 
#include <cstring>
#include <iostream>

#include "Enums.h"
#include "Vek.h"
#include "Vzdelanie.h"


//podla impl. prirucky zodpoveda triede student
namespace structures {

	class UZJ
	{
	private:
		std::string nazov_;
		typUZJ_enum typ_;
		vzdelanie_enum vzdelanieEnum_; //flag od 0 do 7 podla stupna vzdelania
		EVS_enum evs_;
		pohlavie_enum pohl_;
		std::string kod_;
		UZJ* vyssiCelok_;
		Vek* vek_;
		Vzdelanie* vzdel_;
		int pocetObyv_;

	public:
		UZJ(std::string nazov, std::string kod, typUZJ_enum typUZJ, UZJ* vyssiCelok) : nazov_(nazov),
			kod_(kod), typ_(typUZJ), vyssiCelok_(vyssiCelok) {}

		~UZJ() {
			nazov_ = "";
			typ_;
			vzdelanieEnum_;
			evs_;
			pohl_;
			kod_ = "";
			pocetObyv_ = 0;

			delete vyssiCelok_;
			vyssiCelok_ = nullptr;

			delete vek_;
			vek_ = nullptr;

			delete vzdel_;
			vzdel_ = nullptr;



		}


		const std::string& getName() const { return nazov_; };
		const Vek* getVek() { return vek_; };
		const typUZJ_enum& getTyp() const { return typ_; };
		const EVS_enum& getEVS() const { return evs_; };
		const pohlavie_enum& getPohl() const { return pohl_; };
		const std::string& getKod() const { return kod_; };

		//HOPE THISLL WORK 
		const vzdelanie_enum& getEnumVzdelanie() const { return vzdelanieEnum_; };

		const UZJ* getVyssiCelok() { return vyssiCelok_; };
		int& getPocetObyvatelov() { return pocetObyv_; };

	};
}
