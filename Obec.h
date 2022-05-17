#pragma once
#include "IObec.h"

namespace nacitavanieZoSuboru {
	int PorovnajPocet(const void* p1, const void* p2);
	int PorovnajNazov(const void* p1, const void* p2);

	class Obec : public IObec
	{
	private:
		unsigned aPocetObyvatelov = 0;
		char* aNazov = nullptr;
	public:
		Obec(unsigned pocetObyvatelov, const char* nazov);
		Obec(const Obec& zdroj);
		Obec& operator=(const Obec& zdroj) = delete;
		~Obec() override;
		// Inherited via IObec
		virtual unsigned PocetObyvatelov() const override
		{
			return aPocetObyvatelov;
		}
		virtual const char* Nazov() const override
		{
			return aNazov;
		}
		void Vypis() const;

		// Inherited via IObec
		virtual std::string ToString() const override;
	private:
		friend int PorovnajPocet(const void* p1, const void* p2);
		friend int PorovnajNazov(const void* p1, const void* p2);

	};
}

