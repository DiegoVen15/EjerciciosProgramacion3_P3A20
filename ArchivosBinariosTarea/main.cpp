#include <conio.h>
#include "alumnos.h"
#include "materias.h"
#include "notas.h"

#include <iostream>

using namespace std;

int main() {

	agregarNuevosAlumnos();
	listarAlumnos();

	agregarNuevasMaterias();
	listarMaterias();

	agregarNotaMateria();

	alumnos c;
	cout << "Indique el numero de cuenta: ";
	cin >> c.cuenta;
	listarNotas(c.cuenta);
	actualizarPromedio(c.cuenta);

	_getch();
}