#pragma once
#include <string>

namespace nacitavanieZoSuboru {
	class IObec
	{
	public:
		/// <summary>
		/// Rozhranie pre Obec, ktora sa bude nacitavat zo suboru. Analogicky aj okres a kraj...
		/// </summary>
		/// <returns></returns>
		
		virtual const char* Nazov() const = 0;
		virtual int VelkostObce() const = 0;
		virtual int VekovaSkupina() const = 0; //vytvorit flagy - cez prehladavanie veku ich zatriediť do 3 skupin
		virtual unsigned PocetObyvatelov() const = 0; //zistim zosumovanim vsetkych ludi s danym nacitanym  vekom 
		//asi do tabulky -> ako v exceli - musi byt utriedena, aby sa v nej dobre nastavovala hranica pre koniec skupiny vekovej
		virtual int Vzdelanie() const = 0; // dat flagy od 1-8, podla kraja je dany pocet. ...
		virtual ~IObec() = default;
		virtual std::string ToString()const = 0;
		virtual IObec* Clone() = 0;
	};
}

