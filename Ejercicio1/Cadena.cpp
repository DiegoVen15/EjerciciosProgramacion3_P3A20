#include "Cadena.h"
#include <iostream>
#include <conio.h>
#include <cstring>
#include <string>

using namespace std;

Cadena::Cadena(void) : cadena("")
{}
Cadena::Cadena(const char* c01)
{
	setCadena(c01);
}

void Cadena::setCadena(const char* c01)
{
	this->cadena = c01;
}

const char* Cadena::getCadena(void)
{
	return this->cadena;
}

std::ostream& operator<<(std::ostream& out, const Cadena& cad) {
	
	out << "{ ";
	for (int i = 0; i < strlen(cad.cadena); i++)
	{
		out << cad.tamano[LIMITE - strlen(cad.cadena) + i];
	}
	out << " }\n";

	return out;

}

Cadena operator+(const Cadena& c1, const Cadena& c2) {

	Cadena c01;
	Cadena c02;

	const char* cad1;
	const char* cad2;
	
	char* cadena = new char[strlen(cad1) + strlen(cad2) + 2];

	strcpy_s(cadena, strlen(cad1) + 1, cad1);
	cadena[strlen(cad1)] = ' ';
	cadena[strlen(cad1) + 1] = '\0';
	strcat_s(cadena, strlen(cadena) + strlen(cad2) + 1, cad2);

	c01 = cad1;
	c02 = cad2;

	return cadena;
}

int Cadena::strCmp(Cadena cad) {

	Cadena c;

	if (c.tamano == cad.tamano) {

		c.strCmp(cad) == 0;
	}
	else if (c.tamano < cad.tamano) {

		c.strCmp(cad) < 0;
	}
	else {
		c.strCmp(cad) > 0;
	}

	return strCmp(cad);
}
