#pragma once
#include <iostream>
#include <string>
#include "item.h"
using namespace std;

class ListElement
{   public:
	item *information; //pointer catre informatia elementului listei de tip item(nume,pret,gramaj)
	ListElement* previous; //pointer catre elementul precedent din lista
	ListElement* next;//pointer catre urmatorul element din lista
	ListElement(item* _information, ListElement* _previous, ListElement* _next) : information(_information), previous(_previous), next(_next) {}; //constructor al unui element din lista
	ListElement() : information(nullptr), previous(nullptr), next(nullptr) {}; //constructor al unui element din lista
};

