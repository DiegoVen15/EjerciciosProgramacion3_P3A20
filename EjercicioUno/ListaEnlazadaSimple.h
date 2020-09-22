#pragma once
#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include "Nodo.h"

class ListaSimple
{
private:
	Nodo* primero;

public:
	ListaSimple();

	void cargarDatos(int, int, int);
	double obtenerTotalxMes(int);
	void eliminarDatosMes(int);
};

#endif // !LISTA_SIMPLE_H