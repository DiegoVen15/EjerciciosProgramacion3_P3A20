#include "Racional.h"
#include <iostream>

using std::cout;

//implementacion de constructores de clase Racional

// :: operador de resolucion de ambito

Racional::Racional(void) : numerador(-1), denominador(-1)
{}

Racional::Racional(int _numerador, int _denominador)
{
	setNumerador(_numerador);
	setDenominador(_denominador);
}

void Racional::setNumerador(int _numerador)
{
	this->numerador = _numerador;
}

void Racional::setDenominador(int _denominador)
{
	if (_denominador == 0)
	{
		cout << "Imposible asignar valor a variable Denominador\n";
		this->denominador = 1;
		return;
	}

	this->denominador = _denominador;
}

void Racional::imprimirDecimal(void)
{
	if (this->numerador == 0 && this->denominador == 0)
	{
		cout << "Resultado no definido\n";
		return;
	}
	else if (this->denominador == 0)
	{
		cout << "No se puede dividir por cero\n";
		return;
	}

	cout << "Formal Decimal { " << float(this->numerador) / float(this->denominador) << " }\n";

}

void Racional::imprimirRacional(void)
{
	if (this->numerador == 0 && this->denominador == 0)
	{
		cout << "Resultado no definido\n";
		return;
	}
	else if (this->denominador == 0)
	{
		cout << "No se puede dividir por cero\n";
		return;
	}

	cout << "Forma Racional { " << this->numerador << "/" << this->denominador << " }\n";
}

void Racional::simplificar(void)
{
	int mayor = obtenerMayor();

	for (int i = 2; i <= mayor; i++)
	{
		if (numerador % i == 0 && denominador % i == 0)
		{
			numerador /= i;
			denominador /= i;

			i = 1;
		}
	}
}

int Racional::obtenerMayor(void)
{
	return numerador > denominador ? numerador : denominador;
}

int Racional::getDenominador(void)
{
	return this->denominador;
}

int Racional::getNumerador(void)
{
	return this->numerador;
}

Racional Racional::suma(Racional n2)
{
	if (this->denominador == n2.getDenominador())
	{
		return Racional(this->numerador + n2.getNumerador(), this->denominador);
	}

	int num;//nuevo numerador
	int den;//nuevo denominador

	num = (this->denominador * n2.getNumerador()) + (n2.getDenominador() * this->numerador);
	den = this->denominador * n2.getDenominador();

	return Racional(num, den);

}

Racional Racional::resta(Racional n2)
{
	if (this->denominador == n2.getDenominador())
	{
		return Racional(this->numerador - n2.getNumerador(), this->denominador);
	}

	int num;
	int den;

	num = (this->numerador * n2.getDenominador()) - (n2.getNumerador() * this->denominador);
	den = this->denominador * n2.getDenominador();


	return Racional(num, den);
}

Racional Racional::multiplicacion(Racional n2)
{
	return Racional(this->numerador * n2.getNumerador(), this->denominador * n2.getDenominador());
}

Racional Racional::division(Racional n2)
{
	return Racional(this->numerador * n2.getDenominador(), this->denominador * n2.getNumerador());
}

bool Racional::esIgual(Racional n2) {

	float v1;
	float v2;

	v1 = (float(this->numerador) / float(this->denominador));
	v2 = (float(n2.getNumerador()) / float(n2.getDenominador()));

	if (v1 == v2)
		return true;
	else
		return false;
}

bool Racional::esMayor(Racional n2) {

	float v1;
	float v2;

	v1 = (float(this->numerador) / float(this->denominador));
	v2 = (float(n2.getNumerador()) / float(n2.getDenominador()));

	if (v1 > v2)
		return true;
	else
		return false;
}