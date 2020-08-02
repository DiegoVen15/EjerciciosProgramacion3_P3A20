#include <conio.h>
#include "Racional.h"

#include <iostream>
using std::cout;

int main()
{
	Racional r1;
	Racional r2(1, 2);
	Racional r3(1, 3);
	Racional r4(12, 4);

	cout << "r1: \n";
	r1.imprimirDecimal();
	r1.imprimirRacional();

	cout << "\n";

	cout << "r2: \n";
	r2.imprimirDecimal();
	r2.imprimirRacional();

	cout << "\n";

	cout << "r3: \n";
	r3.imprimirDecimal();
	r3.imprimirRacional();

	cout << "\n";

	cout << "r4: \n";
	r4.imprimirDecimal();
	r4.imprimirRacional();

	cout << "\n";

	cout << "r2 + r3: \n";
	Racional r5 = r2.suma(r3);
	r5.imprimirDecimal();
	r5.imprimirRacional();

	cout << "\n";

	cout << "r2 - r3: \n";
	Racional r6 = r2.resta(r3);
	r6.imprimirDecimal();
	r6.imprimirRacional();

	cout << "\n";

	cout << "r2 / r3: \n";
	Racional r7 = r2.division(r3);
	r7.imprimirDecimal();
	r7.imprimirRacional();

	cout << "\n";

	cout << "r2 * r3: \n";
	Racional r8 = r2.multiplicacion(r3);
	r8.imprimirDecimal();
	r8.imprimirRacional();

	cout << "\n";
	cout << "r2 != r3: \n";

	if (r2.esIgual(r3) == true) {
		cout << "Son iguales";
	}
	else {
		cout << "No son iguales";
	}

	cout << "\n";
	cout << "r4 > r3: \n";
	if (r4.esMayor(r3) == true)
		cout << "Es mayor";
	else
		cout << "No es mayor";

	_getch();
}	