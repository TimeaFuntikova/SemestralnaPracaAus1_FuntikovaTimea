#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "Kraj.h"
//#include "ArrayList.h" //po urcitom case zacne detekovat memleaky, akoby nebolschopny spracovat vela dat
#include "linked_list.h"


namespace structures {

	//inspiration from: https://www.youtube.com/watch?v=wRj9PZ2wyZI&ab_channel=TejasPatil


		/// <summary>
		/// slúži na načítavanie zo súborov
		/// </summary>
	class Reader
	{
		//TU SORTEDSEQUENCE TABLE !!!!
		//structures::SortedSequenceTable<int, std::string>* sqceTable_;  //v tvare por.cislo a nazov kraja

		/*
	public:
		Reader();
		structures::Array<Kraj*>* zoznamKrajov_;
		virtual ~Reader() = default;
		//void Start();
	public:
		bool nacitajAtrNaZahodenie(); // NOT DONE
		void nacitajTabulku(); //test, ci funguje, memleaky none
		bool nacitajData(); //suhrn nacitani vsetkych dat a ulozenie ich do prisl udajovych struktur
		bool nacitajKraje(const char* nazov);


		structures::LinkedList<structures::LinkedList<std::string>*>* nacitajKraje(std::string nazovSuboru);

		//structures::SortedSequenceTable<int, std::string>* getSqceTable();
		//char* VytvorVystup(const char* menosuboru);
	//protected:
		//void Uloz(const char* subor, Zoznam& zoznam);
		//void Uloz(std::ofstream& vystup, const Obec& obec);
		//virtual Obec* AlokujObec(const unsigned pocet, const char* nazov);
		//Obec* DajObec(unsigned i) const {return }



		//bool nacitajKraje(char* nazov, structures::SortedSequenceTable<int, std::string>*); //sequenceTable

		bool nacitajObce(); //sequenceTable
		bool nacitajOkresy(); //sequenceTable
		bool nacitajVzdelanie();//sequenceTable
		bool nacitajVek();//sequenceTable

	};
	*/

	public:

		Reader()
		{
			//nacitajObce("C:\\Users\\timka\\source\\repos\\SemestralnaPracaAus1_FuntikovaTimea\\data\\obce.csv");
			nacitajKraje("C:\\Users\\timka\\source\\repos\\SemestralnaPracaAus1_FuntikovaTimea\\data\\kraje.csv");
		}
		~Reader() = default;
		LinkedList<LinkedList<std::string>*>* nacitajObce(std::string fileName);
		LinkedList<LinkedList<std::string>*>* nacitajKraje(std::string fileName);
	};
}

