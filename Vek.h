#pragma once
#include "Enums.h"
#include "Array.h"

class Vek {
private:
	structures::Array<int>* vekSKM_;
	structures::Array<int>* vekSKZ_;
	structures::Array<int>* EVSM_;
	structures::Array<int>* EVSZ_;
public:
	Vek() {
		vekSKM_ = new structures::Array<int>(130); //predpokladajme, ze viac sa nikto nedozil a v najbl. dobe ani nedozije...
		vekSKZ_ = new structures::Array<int>(130);
		EVSM_ = new structures::Array<int>(3);
		EVSZ_ = new structures::Array<int>(3);
	}

	~Vek() {
		delete vekSKM_;
		vekSKM_ = nullptr;
		delete vekSKZ_;
		vekSKZ_ = nullptr;
		delete EVSM_;
		EVSM_ = nullptr;
		delete EVSZ_;
		EVSZ_ = nullptr;
	}

	void pridajVek(pohlavie_enum pohl, int miestoVPoliNaVek)
	{
		switch(pohl) {
			case pohlavie_enum::ZENA : 
				if (miestoVPoliNaVek < 130) {
					vekSKZ_->at(miestoVPoliNaVek) += 1;
				}
				else {
					throw std::logic_error("pridajVek(pohlavie_enum pohl, int miestoVPoliNaVek) : pridava sa vek > 130! ");
				}; break;
			case pohlavie_enum::MUZ :
				if (miestoVPoliNaVek < 130) {
					vekSKM_->at(miestoVPoliNaVek) += 1;
				}
				else {
					throw std::logic_error("pridajVek(pohlavie_enum pohl, int miestoVPoliNaVek) : pridava sa vek > 130! ");
					}
		}
	}

	void pridajZDoEVS(EVS_enum evs) 
	{
		switch (evs) 
		{
			case EVS_enum::PREDPRDUKTIVNI:EVSZ_->at(0) += 1; break;
			case EVS_enum::PRODUKTIVNI:EVSZ_->at(1) += 1; break;
			case EVS_enum::POPRODUKTIVNI: EVSZ_->at(2) += 1; break;
		}
	}

	void PridajMDoEVS(EVS_enum evs) 
	{
		switch (evs) 
		{
		case EVS_enum::PREDPRDUKTIVNI: EVSM_->at(0) += 1; break;
		case EVS_enum::PRODUKTIVNI: EVSM_->at(1) += 1; break;
		case EVS_enum::POPRODUKTIVNI:EVSM_->at(2) += 1; break;
		}
	}


	int getPocetLudiSDanymVekom(pohlavie_enum pohl, int miestoNaVekVPoli) 
	{
		switch (pohl) {
		case pohlavie_enum::MUZ :
			if (miestoNaVekVPoli < 100) {
				return vekSKM_->at(miestoNaVekVPoli);
			}
			else {
				return vekSKM_->at(100);
			}; break;
		case pohlavie_enum::ZENA : 
			if (miestoNaVekVPoli < 100) {
				return vekSKZ_->at(miestoNaVekVPoli);
			}
			else {
				return vekSKZ_->at(100);
			}; break;
		}
	}

	int getPocetZvEVS(EVS_enum evs)
	{
		switch (evs)
		{
			case EVS_enum::PREDPRDUKTIVNI:return EVSZ_->at(0); break;
			case EVS_enum::PRODUKTIVNI:return EVSZ_->at(1); break;
			case EVS_enum::POPRODUKTIVNI: return EVSZ_->at(2); break;
		}
	}

	int getPocetMvEVS(EVS_enum evs) 
	{
		switch (evs)
		{
		case EVS_enum::PREDPRDUKTIVNI:return EVSM_->at(0); break;
		case EVS_enum::PRODUKTIVNI:return EVSM_->at(1); break;
		case EVS_enum::POPRODUKTIVNI: return EVSM_->at(2); break;
		}
	}


	int getPocetEkoVekSkupinuCelkovo(EVS_enum evs) 
	{
		switch (evs) 
		{
			case EVS_enum::PREDPRDUKTIVNI: return EVSM_->at(0) + EVSZ_->at(0);break;
			case EVS_enum::PRODUKTIVNI: return EVSM_->at(1) + EVSZ_->at(1); break;
			case EVS_enum::POPRODUKTIVNI: return EVSM_->at(2) + EVSZ_->at(2); break;
		}
	}

};

