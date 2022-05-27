#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

//#include "ArrayList.h" //po urcitom case zacne detekovat memleaky, akoby nebolschopny spracovat vela dat
#include "linked_list.h"
#include "table/sorted_sequence_table.h"
#include "Vek.h"
#include "Vzdelanie.h"

namespace structures {

	/* * inspirations for reading files from : https://www.youtube.com/watch?v=wRj9PZ2wyZI&ab_channel=TejasPatil
	* https://stackoverflow.com/questions/63470603/what-is-the-best-way-to-take-an-input-line-and-add-the-words-in-the-line-to-a-ve
	* */

	/// <summary>
	/// slúži na načítavanie zo súborov
	/// </summary>
	class Reader
	{
	private:
		LinkedList<LinkedList<std::string>*>* zoznamObci_;
		LinkedList<LinkedList<std::string>*>* zoznamOkresov_;
		LinkedList<LinkedList<std::string>*>* zoznamKrajov_;
		SortedSequenceTable<std::string, Vek*>* tabulkaVek_;
		SortedSequenceTable<std::string, Vzdelanie*>* tabulkaVzdelanie_;

		void pripravNaCitanie(std::string fileName);

		/*pomocne atributy na pracu so subormi*/
		/* 1. pre pripravu na nacitanie obsahu csv suborov, s vyuzitim externej kniznice*/
		std::vector<std::vector<std::string>> content_;
		/* 2. pre pracu s csv subormi*/
		std::string riadok_ = "";
		std::string* riadokPointer_ = nullptr;
		std::string kod_ = "";
		std::string nazov_ = "";
		LinkedList<std::string>* texty_;
		LinkedList<std::string*>* textySTRPointer_ = nullptr;

	public:
		Reader() { nacitajData();}
		~Reader() = default;
		void nacitajData();
		void uvolniPamat();
		LinkedList<LinkedList<std::string>*>* nacitajObce(std::string fileName);//odstranenaDiakritika
		LinkedList<LinkedList<std::string>*>* nacitajOkresy(std::string fileName);//odstranenaDiakritika && "Okres "
		LinkedList<LinkedList<std::string>*>* nacitajKraje(std::string fileName); //odstranenaDiakritika

		SortedSequenceTable<std::string, Vek*>* nacitajVek(std::string fileName);
		SortedSequenceTable<std::string, Vzdelanie*>* nacitajVzdelanie(std::string fileName);

		LinkedList<LinkedList<std::string>*>* getZoznamKObci();
		LinkedList<LinkedList<std::string>*>* getZoznamKOkresov();
		LinkedList<LinkedList<std::string>*>* getZoznamKrajov();

		SortedSequenceTable<std::string, Vek*>* getTabulkaVek();
		SortedSequenceTable<std::string, Vzdelanie*>* getTabulkaVzdelanie();
	};
}

