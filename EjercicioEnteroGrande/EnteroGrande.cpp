#include "EnteroGrande.h"
#include <string>

using namespace std;
EnteroGrande::EnteroGrande(void)
{
	iValor = new int[LIMITE];
	cValor = new char[LIMITE];

	for (int i = 0; i < LIMITE; i++)
	{
		iValor[i] = 0;
		cValor[i] = 'a';
	}
}

std::istream& operator>>(std::istream& in, EnteroGrande& _entero)
{
	in >> _entero.cValor;

	int longitud = strlen(_entero.cValor);
	int posicion = LIMITE - 1;

	for (int i = longitud - 1; i >= 0; i--)
	{
		switch (_entero.cValor[i])
		{
		case '0':
			_entero.iValor[posicion--] = 0;
			break;
		case '1':
			_entero.iValor[posicion--] = 1;
			break;
		case '2':
			_entero.iValor[posicion--] = 2;
			break;
		case '3':
			_entero.iValor[posicion--] = 3;
			break;
		case '4':
			_entero.iValor[posicion--] = 4;
			break;
		case '5':
			_entero.iValor[posicion--] = 5;
			break;
		case '6':
			_entero.iValor[posicion--] = 6;
			break;
		case '7':
			_entero.iValor[posicion--] = 7;
			break;
		case '8':
			_entero.iValor[posicion--] = 8;
			break;
		case '9':
			_entero.iValor[posicion--] = 9;
			break;
		}

	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const EnteroGrande& _entero)
{
	out << "{ ";
	for (int i = 0; i < strlen(_entero.cValor); i++)
	{
		out << _entero.iValor[LIMITE - strlen(_entero.cValor) + i];
	}
	out << " }\n";

	return out;

}

EnteroGrande operator+(const EnteroGrande& entero1, const EnteroGrande& entero2) {

	EnteroGrande resultado;
	string sNumero;

	int cantidadCifras = strlen(entero1.cValor) > strlen(entero2.cValor) ? strlen(entero1.cValor) : strlen(entero2.cValor);

	int acarreo = 0;
	int posicion = LIMITE - 1;
	for (int i = LIMITE - 1; i >= LIMITE - cantidadCifras; i--) {

		int suma = entero1.iValor[i] + entero2.iValor[i] + acarreo;

		if (suma > 9) {

			resultado.iValor[posicion--] = suma - 10;
			acarreo = 1;

			sNumero = to_string(suma - 10) + sNumero;
		}
		else {

			resultado.iValor[posicion--] = suma;
			acarreo = 0;

			sNumero = to_string(suma) + sNumero;
		}
	}

	if (acarreo == 1) {

		resultado.iValor[posicion] = acarreo;
		sNumero = to_string(acarreo) + sNumero;
	}

	strcpy_s(resultado.cValor, strlen(sNumero.c_str()) + 1, sNumero.c_str());
	return resultado;
}