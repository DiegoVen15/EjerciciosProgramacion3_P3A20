#pragma once
#ifndef notas_h
#define notas_h

struct notas {

	int cuentaN;
	int codigoM;
	int nota;
};

void agregarNotaMateria();
void listarNotas(int);
void actualizarPromedio(int);
#endif // !notas_h