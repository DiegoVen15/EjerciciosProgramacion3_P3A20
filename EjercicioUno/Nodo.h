#pragma once
#ifndef NODO_H
#define NODO_H

class Nodo
{
private:
	char* name;
	char* lastName;
	int credit_card;
	int date;
	int year;
	int month;
	double total;
	Nodo* siguiente;

public:
	Nodo();
	Nodo(char*, char*, int, int, int, int, double, Nodo*);

	void setSiguiente(Nodo*);
	Nodo* getSiguiente();

	char* getName();
	char* getLastName();
	int getCredit_card();
	int getDate();
	int getYear();
	int getMonth();
	double getTotal();
};

#endif // !NODO_H