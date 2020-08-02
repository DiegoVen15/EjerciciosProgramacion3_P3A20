#pragma once
#ifndef RACIONAL_H
#define RACIONAL_H

class Racional
{
private:
	int numerador, denominador;
	void simplificar(void);
	int obtenerMayor(void);

public:
	Racional(void);
	Racional(int, int);

	void imprimirRacional(void);
	void imprimirDecimal(void);

	void setNumerador(int);
	void setDenominador(int);

	int getNumerador(void);
	int getDenominador(void);

	Racional suma(Racional);
	Racional resta(Racional);
	Racional division(Racional);
	Racional multiplicacion(Racional);

	bool esIgual(Racional);
	bool esMayor(Racional);

	
};

#endif