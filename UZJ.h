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
		 std::string& getName()  { return nazov_; };
		 Vek* getVek() { return vek_; };
		 typUZJ_enum& getTyp()  { return typ_; };
		 EVS_enum& getEVS()  { return evs_; };
		 pohlavie_enum& getPohl()  { return pohl_; };
		 std::string& getKod() { return kod_; };

		 //HOPE THISLL WORK 
		 vzdelanie_enum& getEnumVzdelanie() { return vzdelanieEnum_; };
		 Vzdelanie* getVzdelaniePocet() { return vzdel_; };

		UZJ* getVyssiCelok() { return vyssiCelok_; };
		int& getPocetObyvatelov() { return pocetObyv_; };

	};
}
