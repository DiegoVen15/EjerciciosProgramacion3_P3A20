#include "utilerias.h"

#include <iostream>
#include <fstream>

using namespace std;

int obtenerCantidadRegistros() {

	fstream obtener("datab.bin", ios::in | ios::binary);

	if (!obtener) {
		
		cout << "Error al abrir archivo\n";
		return -1;
	}

	obtener.seekg(0, ios::end);
	
	int pos = obtener.tellg();

	return pos / sizeof(obtener);
}

void imprimirCantidadPorTipoPago() {

	fstream obtener("datab.bin", ios::in | ios::binary);

	if (!obtener) {

		cout << "Error al abrir archivo\n";
		return;
	}

	int cashRegistro = 0;
	int creditRegistro = 0;
	int NARegistro = 0;

	obtener.seekg(0, ios::beg);

	registro actual;

	string tipoPago;
	obtener.read(reinterpret_cast<char*>(&actual), sizeof(registro));

	while (!obtener.eof()) {

		tipoPago = actual.payment_type;

		if (tipoPago == "Cash") {
			cashRegistro++;
		}
		else if (tipoPago == "Credit") {
			creditRegistro++;
		}
		else if (tipoPago == "NA") {
			NARegistro++;
		}
		
		obtener.read(reinterpret_cast<char*>(&actual), sizeof(registro));
	}

	cout << "Tipos de Registro < Cash: " << cashRegistro << ", Credit: " << creditRegistro << ", NA: " << NARegistro << " >\n";

	obtener.close();
}