#include "utilerias.h"

#include <iostream>
#include <fstream>

using namespace std;

int obtenerCantidadRegistros() {

	ifstream obtener("datab.bin", ios::in | ios::binary);

	if (!obtener) {
		
		cout << "Error al abrir archivo";
		return;
	}

	obtener.seekg(0, ios::beg);

	registro actual;

	obtener.read(reinterpret_cast<char*>(&actual), sizeof(registro));

	while (!obtener.eof()) {
		cout << "Numero de registros: " << actual.id << "\n";

		obtener.read(reinterpret_cast<char*>(&actual), sizeof(registro));
	}

	obtener.close();
}

void imprimirCantidadPorTipoPago() {

	ifstream obtener("datab.bin", ios::in | ios::binary);

	if (!obtener) {

		cout << "Error al abrir archivo";
		return;
	}

	obtener.seekg(0, ios::beg);

	registro actual;

	obtener.read(reinterpret_cast<char*>(&actual), sizeof(registro));

	while (!obtener.eof()) {
		cout << "Tipos de pago:\n";
		cout << "Cash: " << actual.payment_type << "\n";
		cout << "Credit: " << actual.payment_type << "\n";
		cout << "NA: " << actual.payment_type << "\n";

		obtener.read(reinterpret_cast<char*>(&actual), sizeof(registro));
	}

	obtener.close();
}