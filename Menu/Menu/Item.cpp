#include "Item.h"
#include <iostream>
#include <iomanip>
using namespace std;

item::item()
{
	nume = "";
	pret = 0;
	gramaj = 0;
}
void item::create(string name, float price, float weight)
{
	nume = name;
	pret = price;
	gramaj = weight;
}
void item::paste()
{
	int n;
	string s = to_string(gramaj);
	n = 70 - (nume.length() + 5 + s.length());
	cout <<"| " << nume << "   " << gramaj << " g" << setw(n+1) << pret << " lei |";
}
string item::getName()
{
	return nume;
}
float item::getprice()
{
	return pret;
}
float item::getgramaj()
{
	return gramaj;
}
