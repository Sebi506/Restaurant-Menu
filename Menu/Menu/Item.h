#pragma once
#include <iostream>
#include <string>
using namespace std;

class item
{
	string nume; //numele preparatului
	float pret; //pretul preparatului 
	float gramaj; //gramajul preparatului

public:
	item();
	void create(string name, float price, float weight); //functie care initializeaza un preparat cu nume,pret si greutate
	string getName(); //functie care retunreaza numele
	float getprice(); //functie care returneaza pretul
	void paste(); //functie care afiseaza numele,gramajul si preparatul
	float getgramaj(); //functie care returneaza gramajul
};