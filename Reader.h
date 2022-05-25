#pragma once
#include <iostream>
#include "table/sorted_sequence_table.h"
#include "Array.h"
#include "linked_list.h"
#include "Kraj.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

//inspiration from: https://www.youtube.com/watch?v=wRj9PZ2wyZI&ab_channel=TejasPatil


	/// <summary>
	/// slúži na načítavanie zo súborov
	/// </summary>
	class Reader
	{
	private:

		//TU SORTEDSEQUENCE TABLE !!!!
		//structures::SortedSequenceTable<int, std::string>* sqceTable_;  //v tvare por.cislo a nazov kraja
	
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
			/*
		bool nacitajObce(); //sequenceTable
		bool nacitajOkresy(); //sequenceTable
		bool nacitajVzdelanie();//sequenceTable
		bool nacitajVek();//sequenceTable
		*/
	};

