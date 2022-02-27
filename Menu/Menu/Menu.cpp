#pragma once
#include <iostream>
#include "Page.h"
#include "Item.h"
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

Page menu[5];
int nrpag = 2, currentpag = 1;
Page bon;

void printfirstpage()//functie care afiseaza cuprinsul
{
	cout << "|" << setw(35 + 5 / 2) << "Meniu" << setw(35 - 5 / 2 + 1) << "|" << endl;
	cout << "|" << setw(71) << "|" << endl;
	cout << "|" << setw(71) << "|" << endl;
	cout << "| " << "Paginile meniului"<<setw(70-17)<<"|"<<endl;
	cout << "|" << setw(71) << "|" << endl;
	cout << "| " << "1.Garnituri"<<setw(70-11)<<"|"<<endl;
	cout << "| " << "2.Supe"<<setw(70-6)<<"|"<<endl;
	cout << "| " << "3.Pizza"<<setw(70-7)<<"|"<<endl;
	cout << "| " << "4.Gratar"<<setw(70-8)<<"|"<<endl;
	cout << "| " << "5.Desert"<<setw(70-8)<<"|"<<endl;
	cout << "| " << "6.Bauturi"<<setw(70-9)<<"|"<<endl<<endl<<endl;
}
void printpage() //functie care afiseaza urmatoarea pagina
{
		if (currentpag + 1 <= nrpag)
		{
			system("cls");
			menu[++currentpag].print();
			cout << "asdaf";
		}
}
void printpage(int nr) //functie care afiseaza o pagina dupa numarul acesteia
{
if(nr>0 && nr<=nrpag)
{   
	cout << menu[nr].gettitle()<<endl<<endl;
	system("cls");
	menu[nr].print();
	currentpag = nr;
	cout<<"| " << "Pagina : " << currentpag <<setw(60)<<"|" << endl << endl << endl;
}
else
{
	cout << menu[++currentpag].gettitle() << endl << endl;
	system("cls");
	menu[currentpag].print();
}
}
void printop() //functie care afiseaza optiunile utilizatorului
{
	cout << "Optiuni:" << endl;
	cout << "1.Adauga preparat" << endl;
	cout << "2.Sterge preparat" << endl;
	cout << "3.Arata bonul curent" << endl; 
	cout << "4.Pagina urmatoare" << endl;
	cout << "5.Pagina precedenta" << endl;
	cout << "6.Pagina la care vrei sa sari" << endl;
	cout << "7.Tipareste bon" << endl;
	cout << "8.Anuleaza" << endl;
	cout << "9.Prima pagina" << endl;
	cout << "Optiune aleasa : " << endl;
}
float gettotal()//functie care calculeaza totalul de plata de pe bon
{
	float suma = 0;
	item* temp;
	for (int i = 1; i <= bon.getSize(); i++)
	{
		temp = bon.get(i);
		suma = suma + temp->getprice();
	}
	return suma;
}
void applyop(int& op) //functie care aplica optiunea aleasa de utilizator
{
	int op2;
	switch (op)
	{
	case 1:
	{
		printpage(currentpag);
		cout << "Alege preparatul pe care vrei sa il adaugi : "; cin >> op2;
		while (op2 < 1 || op2>menu[currentpag].getSize())
		{
			printpage(currentpag);
			cout << "Alege preparat : "; cin >> op2;
		}
		bon.add(menu[currentpag].get(op2));
		break;
	}
	case 2:
	{
		system("cls");
		bon.print();
		cout << "Alege preparatul pe care vrei sa il stergi : "; cin >> op2;
		while (op2<1 || op2>bon.getSize())
		{
			system("cls");
			bon.print();
			cout << "Alege preparatul pe care vrei sa il stergi : "; cin >> op2;
		}
		bon.remove(op2);

		break;
	}
	case 3:
	{   float suma = gettotal();
	system("cls");
	bon.print();
	cout << "Total : " << suma << endl;
	cout << "1.Inapoi" << endl;
	cout << "Optiune : ";
	cin >> op;
	while (op != 1)
	{
		system("cls");
		bon.print();
		cout << "Total : " << suma << endl;
		cout << "1.Inapoi" << endl;
		cout << "Optiune : ";
		cin >> op;
	}
	break;
	}
	case 4: { printpage(); break; }
	case 5: { printpage(--currentpag); break; }
	case 6:
	{   printpage(currentpag);
	cout << "Pagina la care vreti sa sariti : "; cin >> op2;
	while (op2<0 || op2>nrpag)
	{
		printpage(currentpag);
		cout << "Pagina la care vreti sa sariti : "; cin >> op2;
	}
	printpage(op2); break;
	}
	case 7: {
		system("cls");
		bon.print();
		cout << "Total : " << gettotal();
		break;
	}
	case 8: {
		system("cls");
		cout << "Bon anulat,vreti sa reincepeti?";
		cout << "1.Da" << endl;
		cout << "2.Nu" << endl;
		cout << "Optiune : "; cin >> op2;
		while (op2 < 1 || op2>2)
		{
			system("cls");
			cout << "Bon anulat,vreti sa reincepeti?" << endl;
			cout << "1.Da" << endl;
			cout << "2.Nu" << endl;
			cout << "Optiune : "; cin >> op2;
		}
		if (op2 == 1) {
			op = 1; bon.clear();
		}
		break;
	}

	case 9: {
		system("cls");
		printfirstpage();
		cout << "1.Alege pagina" << endl;
		cout << "Optiune : "; cin >> op;
		while(op<1 || op>6)
		{
			system("cls");
			printfirstpage();
			cout << "Alege pagina" << endl;
			cout << "Optiune : "; cin >> op;
		}
		printpage(op);
	}
	}

}
void startmenu() //functie care incepe programul
{
	int op=-1;
	while (op!=8 && op!=7)
	{
		printpage(currentpag);
		printop();
		cin >> op;
		while(op<1 || op>9)
		{
			printpage(currentpag);
			if(op!=9)printop();
			cin >> op;
		}
		applyop(op);
		
	}
}
int main()
{
	Page* p = new Page();
	item* i1 =new item();
	item* i2 = new item();
	item* i3 = new item();
	item* i4 = new item();
	item* i5 = new item();
	item* i6 = new item();
	item* i7 = new item();
	item* i8 = new item();
	item* i9 = new item();
	item* i10 = new item();
	menu[1].givetitle("Garnituri");
	menu[2].givetitle("Supe");
	menu[3].givetitle("Pizza");
	menu[4].givetitle("Gratar");
	menu[5].givetitle("Desert");
	menu[6].givetitle("Bauturi");
	i1->create("Cartofi prajiti",5 ,100 );
	menu[1].add(i1);
	i2->create("Salata de rosii",6 ,120 );
	menu[1].add(i2);
	i3->create("Salata de varza",6 ,120 );
	menu[1].add(i3);
	i4->create("Salata de vinete",7 ,130 );
	menu[1].add(i4);
	i5->create("Supa de pui",8 ,150 );
	menu[2].add(i5);
	i6->create("Supa de legume",7 ,150 );
	menu[2].add(i6);
	i7->create("Supa crema de ciuperci",9 ,150 );
	menu[2].add(i7);
	i8->create("Pizza diavolo",25 ,300 );
	menu[3].add(i8);
	i9->create("Pizza vegetariana",23 ,300 );
	menu[3].add(i9);
	i10->create("Pizza cu ton",24 ,300 );
	menu[3].add(i10);
	startmenu();
	//printfirstpage();
}