#pragma once
#include "ListElement.h"

class Page
{   string title; //titlul paginii 
	ListElement* first; //pointer catre primul preparat de pe pagina
	ListElement* last; //pointer catre ultimul preparat de pe pagina
	int size; //numarul de preparate de pe pagina
	
public:
	Page() : title(""),first(nullptr), last(nullptr), size(0) {}; //constructor al paginii
	~Page() { clear(); }; //destructor al paginii
	void givetitle(string name); //functie care seteaza titlul paginii
	string gettitle(); //functie care returneaza titlul paginii
	int getSize(); //functie care returneaza dimensiunea paginii(numarul de preparate)
	int isEmpty();//functie care returneaza 1 daca pagina este goala,0 in caz contrat
	void clear(); //functie care sterge lista de preparate a paginiii
	void add(item* product); //functie care adauga un element in lista(preparat) la finalul paginii
	void add(item* product, int position);//functie care adauga un element in lista la o pozitie la alegere
	void remove(ListElement* element);//functie care sterge un element din lista dupa pointerul acestuia
	void remove();//functie care sterge ultimul element din lista
	void remove(int position);//functie care sterge un element din lista dupa pozitia acestuia
	void remove(string name); //functie care sterge un element din lista dupa nume
	item* get(int position); //functie care returneaza un preparat din lista dupa pozitie
	void print();//functie care afiseaza pagina
};

