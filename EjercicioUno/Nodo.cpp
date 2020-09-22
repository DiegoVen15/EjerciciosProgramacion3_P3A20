#include "Nodo.h"

Nodo::Nodo() : name(), lastName(), credit_card(-1), date(-1), year(-1), month(-1), total(-1), siguiente(nullptr)
{}

Nodo::Nodo(char* name1, char* lastName1, int credit_card1, int date1, int year1, int month1, double total1, Nodo* _siguiente) 
	: name(name1), lastName(lastName1), credit_card(credit_card1), date(date1), year(year1), month(month1), total(total1), siguiente(_siguiente)
{}

void Nodo::setSiguiente(Nodo* _siguiente)
{
	this->siguiente = _siguiente;
}

Nodo* Nodo::getSiguiente()
{
	return this->siguiente;
}

char* Nodo::getName() {

	return this->name;
}

char* Nodo::getLastName() {

	return this->lastName;
}

int Nodo::getCredit_card() {

	return this->credit_card;
}

int Nodo::getDate() {

	return this->date;
}

int Nodo::getYear() {

	return this->year;
}

int Nodo::getMonth() {

	return this->month;
}

double Nodo::getTotal() {

	return this->total;
}
