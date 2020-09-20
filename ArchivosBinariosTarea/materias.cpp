#include "materias.h"
#include <fstream>
#include <iostream>

using namespace std;

void agregarNuevasMaterias() {

	ofstream materiasOut("alumnos.dat", ios::out | ios::app | ios::binary);

	if (!materiasOut) {

		cout << "Error al abrir archivo\n";
		return;
	}

	materias nuevo;
	cout << "Ingrese el nombre: ";
	cin >> nuevo.nMateria;

	cout << "Ingrese el codigo: ";
	cin >> nuevo.codigo;

	cout << "Ingrese la unidad valorativa: ";
	cin >> nuevo.uv;

	materiasOut.write(reinterpret_cast<const char*>(&nuevo), sizeof(materias));
	materiasOut.close();
}

void listarMaterias() {

	ifstream materiasIn("alumnos.dat", ios::in | ios::binary);

	if (!materiasIn) {

		cout << "Error al abrir archivo\n";
		return;
	}

	materiasIn.seekg(0, ios::beg);

	materias actual;

	materiasIn.read(reinterpret_cast<char*>(&actual), sizeof(materias));

	while (!materiasIn.eof()) {

		cout << "Materias{ nombre: " << actual.nMateria << ", codigo: " << actual.codigo << ", unidad valorativa: " << actual.uv << " }\n";

		materiasIn.read(reinterpret_cast<char*>(&actual), sizeof(materias));
	}

	materiasIn.close();
}