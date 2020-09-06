#pragma once
#ifndef EMPRESALISTA_H
#define EMPRESALISTA_H

#include "EmpleadoNodo.h"

class empresaLista {

private:

	empleadoNodo* primero, * ultimo;

public:

	empresaLista();

	bool estaVacia();
	bool agregarEmpleado(int, char*, float);
	bool insertarEmpleado(int, char*, float);
	bool eliminarEmpleado(int);

	void actualizarSalarios(float);
	void imprimirEmpleados();
};

#endif // !EMPRESALISTA_H