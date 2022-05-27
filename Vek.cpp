#include "Vek.h"

namespace structures {

	Vek::Vek() {
		vekSKM_ = new Array<int>(101); //101 == tolko je zaznamov pre obe pohlavia [0-100+]
		vekSKZ_ = new Array<int>(101);
		EVSM_ = new Array<int>(3);
		EVSZ_ = new Array<int>(3);
	}

	Vek::~Vek() {
		delete vekSKM_;
		delete vekSKZ_;
		delete EVSM_;
		delete EVSZ_;
		vekSKM_ = nullptr;
		vekSKZ_ = nullptr;
		EVSM_ = nullptr;
		EVSZ_ = nullptr;
	}

	void Vek::pridajVek(pohlavie_enum pohl, int miestoVPoliNaVek, int kolkoSaNapocitalo) {
		switch (pohl) {
		case pohlavie_enum::ZENA:
			if (miestoVPoliNaVek < 100) {
				vekSKZ_->at(miestoVPoliNaVek) += kolkoSaNapocitalo;
			}
			else
			{
				vekSKZ_->at(100) += kolkoSaNapocitalo;
			}; break;
		case pohlavie_enum::MUZ:
			if (miestoVPoliNaVek < 100) {
				vekSKM_->at(miestoVPoliNaVek) += kolkoSaNapocitalo;
			}
			else
			{
				vekSKM_->at(100) += kolkoSaNapocitalo;
			}; break;
		}
	}

	void Vek::pridajDoEVS(Vek* vek) 
	{
		//PredProduktivni
		for (int i = 0; i < 15; i++)
		{
			getEVSM()->at(0) += vek->getvekSM()->at(i);
			getEVSZ()->at(0) += vek->getvekSZ()->at(i);
		}

		//Produktivni
		for (int i = 15; i < 65; i++)
		{
			getEVSM()->at(1) += vek->getvekSM()->at(i);
			getEVSZ()->at(1) += vek->getvekSZ()->at(i);
		}

		//Poproduktivni
		for (int i = 65; i < 101; i++)
		{
			getEVSM()->at(2) += vek->getvekSM()->at(i);
			getEVSZ()->at(2) += vek->getvekSZ()->at(i);
		} 

	}

	void Vek::pridajZDoEVS(EVS_enum evs, int kolkosaPridava)
	{
		switch (evs) {
		case EVS_enum::PREDPRDUKTIVNI:EVSZ_->at(0) += kolkosaPridava; break;
		case EVS_enum::PRODUKTIVNI:EVSZ_->at(1) += kolkosaPridava; break;
		case EVS_enum::POPRODUKTIVNI: EVSZ_->at(2) += kolkosaPridava; break;
		}
	}

	void Vek::pridajMDoEVS(EVS_enum evs, int kolkosaPridava)
	{
		switch (evs)
		{
		case EVS_enum::PREDPRDUKTIVNI: EVSM_->at(0) += kolkosaPridava; break;
		case EVS_enum::PRODUKTIVNI: EVSM_->at(1) += kolkosaPridava; break;
		case EVS_enum::POPRODUKTIVNI:EVSM_->at(2) += kolkosaPridava; break;
		}
	}

	Array<int>* Vek::getvekSM()
	{
		return vekSKM_;
	}

	Array<int>* Vek::getvekSZ()
	{
		return vekSKZ_;
	}

	Array<int>* Vek::getEVSM()
	{
		return EVSM_;
	}

	Array<int>* Vek::getEVSZ()
	{
		return EVSZ_;
	}


	int Vek::getPocetLudiSDanymVekom(pohlavie_enum pohl, int miestoNaVekVPoli)
	{
		switch (pohl) {
		case pohlavie_enum::MUZ:
			if (miestoNaVekVPoli < 100) {
				return vekSKM_->at(miestoNaVekVPoli);
			}
			else {
				return vekSKM_->at(100);
			}; break;
		case pohlavie_enum::ZENA:
			if (miestoNaVekVPoli < 100) {
				return vekSKZ_->at(miestoNaVekVPoli);
			}
			else {
				return vekSKZ_->at(100);
			}; break;
		}
	}

	int Vek::getPocetZvEVS(EVS_enum evs)
	{
		switch (evs)
		{
		case EVS_enum::PREDPRDUKTIVNI:return EVSZ_->at(0); break;
		case EVS_enum::PRODUKTIVNI:return EVSZ_->at(1); break;
		case EVS_enum::POPRODUKTIVNI: return EVSZ_->at(2); break;
		}
	}

	int Vek::getPocetMvEVS(EVS_enum evs)
	{
		switch (evs)
		{
		case EVS_enum::PREDPRDUKTIVNI:return EVSM_->at(0); break;
		case EVS_enum::PRODUKTIVNI:return EVSM_->at(1); break;
		case EVS_enum::POPRODUKTIVNI: return EVSM_->at(2); break;
		}
	}


	int Vek::getPocetEkoVekSkupinCelkovo(EVS_enum evs)
	{
		switch (evs)
		{
		case EVS_enum::PREDPRDUKTIVNI: return EVSM_->at(0) + EVSZ_->at(0); break;
		case EVS_enum::PRODUKTIVNI: return EVSM_->at(1) + EVSZ_->at(1); break;
		case EVS_enum::POPRODUKTIVNI: return EVSM_->at(2) + EVSZ_->at(2); break;
		}
	}
	
}
