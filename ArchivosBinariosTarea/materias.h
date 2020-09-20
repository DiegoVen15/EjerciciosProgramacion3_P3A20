#pragma once
#ifndef materias_h
#define materias_h

struct materias {

	int codigo;
	char nMateria[20];
	int uv;
};

void agregarNuevasMaterias();
void listarMaterias();
#endif // !materias_h
