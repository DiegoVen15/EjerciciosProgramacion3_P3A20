#include "Byte.h"
#include <cmath>
#include <string>


Byte::Byte(void)
{
	//inicializar el byte en 0
	for (int i = 0; i < 8; i++)
	{
		this->bits[i] = 0;
	}
}



//10001101,  00001101
Byte::Byte(const char* _byte)
{

	for (int i = 0; i < 8; i++)
	{
		this->bits[i] = _byte[i] - 48;
	}
}

//destructor de la clase
Byte::~Byte()
{}

std::ostream& operator<<(std::ostream& out, const Byte& _byte)
{
	// { 00001010 }
	out << "{ ";
	for (int i = 0; i < 8; i++)
	{
		//cout << 1
		out << _byte.bits[i];
	}
	out << " }\n";

	return out;
}

Byte operator+(const Byte& _b1, const Byte& _b2)
{
	Byte nuevo;
	int acarreo = 0;

	for (int i = 8 - 1; i >= 0; i--)
	{
		int resultado = 0;

		if (acarreo == 0)
		{
			if (_b1.bits[i] == 0 && _b2.bits[i] == 0)
			{
				resultado = 0;
				acarreo = 0;
			}
			else if (_b1.bits[i] == 1 && _b2.bits[i] == 0 ||
				_b1.bits[i] == 0 && _b2.bits[i] == 1)
			{
				resultado = 1;
				acarreo = 0;
			}
			else if (_b1.bits[i] == 1 && _b2.bits[i] == 1)
			{
				resultado = 0;
				acarreo = 1;
			}
		}
		else //cuando acarreo sea 1
		{    //1
			//0010
			//0111
			//====
			//1001

			if (_b1.bits[i] == 0)
			{
				resultado = 1;
				acarreo = 0;
			}
			else
			{
				resultado = 0;
				acarreo = 1;
			}

			if (resultado == 0 && _b2.bits[i] == 0)
			{
				resultado = 0;
			}
			else if (resultado == 0 && _b2.bits[i] == 1)
			{
				resultado = 1;
			}
			else if (resultado == 1 && _b2.bits[i] == 0)
			{
				resultado = 1;
				acarreo = 0;
			}
			else if (resultado == 1 && _b2.bits[i] == 1)
			{
				resultado = 0;
				acarreo = 1;
			}

		} //fin del else princial acarreo

		nuevo.bits[i] = resultado;

	}// fin de ciclo for

	return nuevo;

}

int Byte::obtenerDecimal()
{
	int resultado = 0;
	int exponente = 0;

	for (int i = 8 - 1; i >= 0; i--, exponente++)
	{

		if (this->bits[i] == 1)
			resultado += pow(2, exponente);

	}

	return resultado;

}

void Byte::obtenerOctal(int resultado) {
	if (resultado > 7) {
		obtenerOctal(resultado / 8);
	}
	std::cout << resultado % 8;
}

void Byte::obtenerHexadecimal(int resultado) {

	std::string hex;
	int cont = 0;
	int aux = 0;
	int i = 7;
	do {

		for (int i = 0; i < 4; i++) {
			if (i < 0)
				break;
			aux += (pow(2, i) * this->bits[i]);
			i--;
		}

		if (aux >= 0 && aux <= 9)
			hex = std::to_string(aux) + hex;
		else if (aux == 10) {
			hex = 'A' + hex;
		}
		else if (aux == 11) {
			hex = 'B' + hex;
		}
		else if (aux == 12) {
			hex = 'C' + hex;
		}
		else if (aux == 13) {
			hex = 'D' + hex;
		}
		else if (aux == 14) {
			hex = 'E' + hex;
		}
		else if (aux == 15) {
			hex = 'F' + hex;
		}

		aux = 0;
		cont++;

	} while (i >= 0);
}

Byte Byte::operator~(void) {

	Byte nuevo;

	for (int i = 8 - 1; i >= 0; i--) {

		nuevo.bits[i] = this->bits[i] == 1 ? 0 : 1;
	}

	return nuevo;
}

Byte operator-(const Byte& b1, const Byte& b2) {
	Byte nuevo;
	int acarreo = 0;

	for (int i = 8 - 1; i >= 0; i--) {

		int resultado = 0;
		if (acarreo == 1) {
			if (b1.bits[i] == 1) {

				resultado = 0;
				acarreo = 1;	
			}
			else {
				resultado = 1;
				acarreo = 0;
			}
			if (resultado == 0 && b2.bits[i] == 0) {
				resultado = 0;
				//acarreo = 0;
			}
			else if (resultado == 0 && b2.bits[i] == 1) {
				resultado = 1;
				acarreo = 1;
			}
			else if (resultado == 1 && b2.bits[i] == 0) {
				resultado = 1;
				acarreo = 0;
			}
			else if (resultado == 1 && b2.bits[i] == 1) {
				resultado = 0;
				acarreo = 0;
			}
		}
		else {
			if (b1.bits[i] == 0 && b2.bits[i] == 0) {
				resultado = 0;
				acarreo = 0;
			}
			else if (b1.bits[i] == 1 && b2.bits[i] == 0) {
				resultado = 1;
				acarreo = 0;
			}
			else if (b1.bits[i] == 0 && b2.bits[i] == 1) {
				resultado = 0;
				acarreo = 1;

			}
			else if (b1.bits[i] == 1 && b2.bits[i] == 1) {
				resultado = 0;
				//acarreo = 0;
			}
		}
		nuevo.bits[i] = resultado;
	}
	return nuevo;
}

Byte operator*(const Byte& b1, const Byte& b2) {

	Byte nuevo;
	int acarreo = 0;

	for (int i = 8 - 1; i >= 0; i--) {

		int resultado = 0;
		int a = i - 1;	
		if (b2.bits[i] == 0 && b1.bits[i] == 0 ) {
			resultado = 0;
			acarreo = 0;

			if (b1.bits[a] == 0 && b2.bits[a] == 0) {
				resultado = 0;
				acarreo = 1;
			}
			else {	
				resultado = 10;
			}
			if (b1.bits[a] == 1 || b2.bits[a] == 1) {
				resultado = 1;
			}

		}
		if (b1.bits[i] == 1 && b2.bits[i] == 0) {
			resultado = 0;
			acarreo = 0;
		}
		if (b1.bits[i] == 0 && b2.bits[i] == 1) {
			resultado = 0;
			acarreo = 0;
		}
		if (b2.bits[i] == 1 && b1.bits[i] == 1) {
			resultado = 1;
			acarreo = 0;
		}
		nuevo.bits[i] = resultado;
	}
	return nuevo;
}

Byte operator&(const Byte& b1, const Byte& b2) {
	Byte nuevo;

	for (int i = 0; i < 8; i++)
	{
		if ((b1.bits[i] && b2.bits[i]) == 0)
		{
			nuevo.bits[i] = 0;
		}
		else if ((b1.bits[i] && b2.bits[i]) == 1)
		{
			nuevo.bits[i] = 1;
		}
	}
	return nuevo;
}

Byte operator|(const Byte& b1, const Byte& b2) {
	Byte nuevo;

	for (int i = 0; i < 8; i++)
	{
		if ((b1.bits[i] && b2.bits[i]) == 0)
		{
			nuevo.bits[i] = 0;
		}
		if (b1.bits[i] || b2.bits[i] == 1)
		{
			nuevo.bits[i] = 1;
		}
	}
	return nuevo;
}

Byte operator^(const Byte& b1, const Byte& b2) {

	Byte nuevo;

	for (int i = 0; i < 8; i++)
	{
		if ((b1.bits[i] && b2.bits[i]) == 1)
		{
			nuevo.bits[i] = 0;
		}
		else if (b1.bits[i] || b2.bits[i] == 1)
		{
			nuevo.bits[i] = 1;
		}
		else if ((b1.bits[i] && b2.bits[i]) == 0)
		{
			nuevo.bits[i] = 0;
		}

	}

	return nuevo;
}

