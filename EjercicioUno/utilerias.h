#pragma once
#ifndef UTILERIAS_H
#define UTILERIAS_H

struct registro {

	int id;
	char name[30];
	char lastname[30];
	char credit_card[25];
	char date[12];
	short int day;
	short int month;
	short int year;
	char payment_type[10];
	double total;
	char business_type[20];
	char business_name[50];
};

	int obtenerCantidadRegistros();
	void imprimirCantidadPorTipoPago();
#endif // !UTILERIAS_H
