#pragma once
#ifndef alumnos_h
#define alumnos_h

struct alumnos {

	int cuenta;
	char nombre[30];
	float promedio;
};

void agregarNuevosAlumnos();
void listarAlumnos();
#endif // !alumnos_h