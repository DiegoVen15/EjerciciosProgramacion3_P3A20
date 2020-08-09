#include <iostream>
#include <conio.h>

#include "Byte.h"

using std::cout;

int main()
{
	Byte b1("00001010");
	Byte b2("00011011");

	cout << "Binario 1: " << b1 << "\n";
	cout << "Binario 2: " << b2 << "\n";

	Byte b3 = b1 + b2;

	cout << "b1 + b2 = " << b3 << "\n";
	cout << "Valor Decimal b3 = " << b3.obtenerDecimal() << "\n";
	cout << "Valor Octal b3 = " << b3.obtenerOctal() << "\n";
	cout << "Valor Hexadecimal b3 = " << b3.obtenerHexadecimal() << "\n";

	Byte b5 = b1 & b2;
	cout << "AND: " << b5 << "\n";
	Byte b4 = b1 | b2;
	cout << "OR: " << b4 << "\n";
	Byte b6 = b1 ^ b2;
	cout << "XOR: " << b6 << "\n";
	cout << "NOT: " << ~b1 << "\n";

	Byte b7 = b1 - b2;
	cout << "b1 - b2= " << b7 << "\n";
	Byte b8 = b1 * b2;
	cout << "b1 * b2 = " << b8 << "\n";
	_getch();
}