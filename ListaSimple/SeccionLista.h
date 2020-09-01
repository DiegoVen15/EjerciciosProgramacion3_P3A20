#pragma once
#ifndef SECCIONLISTA_H
#define SECCIONLISTA_H

#include "AlumnoNodo.h"

class SeccionLista {

private:
	AlumnoNodo* primero;

public:
	SeccionLista(void);
	bool estaVacia();
	void agregarAlumno(char* nombre, float nota);
	void listarSeccion();
	int cantidadAprobados();
};
#endif // !SECCIONLISTA_H