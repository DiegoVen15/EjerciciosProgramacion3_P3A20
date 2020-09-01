
#include "SeccionLista.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main() {

	SeccionLista sl;
	sl.agregarAlumno((char*)"David", 91);
	sl.agregarAlumno((char*)"Andrea", 40);
	sl.agregarAlumno((char*)"Carmelo", 80);

	sl.listarSeccion();

	cout << "Reprobados: " << sl.cantidadAprobados() << "\n";

}