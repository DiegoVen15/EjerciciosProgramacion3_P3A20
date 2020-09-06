#include <conio.h>
#include "EmpresaLista.h"

int main() {

	empresaLista el;

	el.agregarEmpleado(1001, (char*)"David", 800);
	el.agregarEmpleado(1002, (char*)"Jose", 1200);
	el.agregarEmpleado(1003, (char*)"Carmelo", 1700);

	el.imprimirEmpleados();

	el.insertarEmpleado(1004, (char*)"Patricio", 1100);

	el.imprimirEmpleados();

	el.eliminarEmpleado(1002);

	el.imprimirEmpleados();

	el.actualizarSalarios(0.5);

	el.imprimirEmpleados();

	_getch();
}