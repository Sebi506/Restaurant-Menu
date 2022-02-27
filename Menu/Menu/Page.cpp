#include "Page.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void Page::givetitle(string name)
{
	title = name;
}
string Page::gettitle()
{
	return title;
}
int Page::getSize(){
	return size;
}
int Page::isEmpty(){
	return (size == 0);
}
void Page::clear(){
	ListElement* tmp;
	while (first != nullptr) {
		tmp = first;
		first = first->next;
		delete tmp;
		size--;
	}
	first = nullptr;
	last = nullptr;
}
void Page::add(item* product){
	ListElement* element = new ListElement();
	element->information = product;
	size++;
	if(first==nullptr) 
	{
		first = element;
		last = first;
		return;
	}
	element->previous = last;
	element->next = nullptr;
	last->next = element;
	last = element;

}
void Page::add(item* product, int position){
	if (position > size + 1) {
		cout << "Invalid position"; return;
	}
	if(isEmpty() || position==size)
	{
		add(product);
		return;
	}

	ListElement* temp=first;
	ListElement* element = new ListElement();
	element->information = product;
	int i = 1;
	while(i<position)
	{
		temp = temp->next;
		i++;
	}
	temp->previous->next = element;
	element->next = temp;
	element->previous = temp->previous;
	temp->previous = element;
	size++;
}
void Page::remove(ListElement* element)
{   ListElement* temp;
	if (first == last)
	{
		delete first;
		size--;
		first = nullptr;
		last = nullptr;
		return;
	}
	if (element == first) {
		temp = first;
		first = first->next;
		first->previous = nullptr;
		delete temp;
		size--;
		return;
	}
	if (element == last) {
		temp = last;
		last = last->previous;
		last->next = nullptr;
		delete temp;
		size--;
		return;
	}
element->previous->next = element->next;
element->next->previous = element->previous;
delete element;
size--;
}
void Page::remove(){
	if (isEmpty()) return;
	remove(last);
}
void Page::remove(int position){
	if (isEmpty()) return;
	if (position==size) { remove(); return; }
	ListElement* temp = first;
	int i = 1;
	while (i <position)
	{
		temp = temp->next;
		i++;
	}
	remove(temp);
}
void Page::remove(string name){

	if (isEmpty()) return;
	if (last->information->getName() == name)
	{
		remove(); return;
	}
	ListElement* temp = first;
	while (temp->information->getName() != name && temp ->next!= nullptr)
	{
		temp = temp->next;
	}
	if (temp ->next==nullptr) {
		cout << "Item not found"; return;
	}
	remove(temp); 
}
item* Page::get(int position)
{
	if (isEmpty()) return 0;
	if (position == size) { return last->information; }
	if (position == 1) { return first->information; }
	ListElement* temp = first->next;
	int i = 2;
	while (i < position)
	{
		temp = temp->next;
		i++;
	}
	return temp->information;
}
void Page::print(){
	cout  <<"|" << setw(35+title.length()/2) << title <<setw(35-title.length()/2+1)<<"|"<< endl;
	cout << "|" << setw(71) << "|" << endl;
	cout << "|" << setw(71) << "|" << endl;
	ListElement* temp = first;
	for (int i = 1; i <= size; i++)
	{
		temp->information->paste();
		temp = temp->next;
		cout << endl <<"|"<<setw(71)<<"|"<< endl << "|" << setw(71) << "|"<< endl;
	}
}

