#include "alumnos.h"

#include <iostream>
#include <fstream>

using namespace std;

void agregarNuevosAlumnos() {

	ofstream alumnosOut("alumnos.dat", ios::out | ios::app | ios::binary);

	if (!alumnosOut) {

		cout << "Error al abrir archivo\n";
		return;
	}

	alumnos nuevo;
	cout << "Ingrese el nombre: ";
	cin >> nuevo.nombre;

	cout << "Ingrese el numero de cuenta: ";
	cin >> nuevo.cuenta;

	cout << "Ingrese el promedio: ";
	cin >> nuevo.promedio;

	alumnosOut.write(reinterpret_cast<const char*>(&nuevo), sizeof(alumnos));
	alumnosOut.close();
}

void listarAlumnos() {

	ifstream alumnosIn("alumnos.dat", ios::in | ios::binary);

	if (!alumnosIn) {

		cout << "Error al abrir archivo\n";
		return;
	}

	alumnosIn.seekg(0, ios::beg);

	alumnos actual;

	alumnosIn.read(reinterpret_cast<char*>(&actual), sizeof(alumnos));

	while (!alumnosIn.eof()) {

		cout << "Alumno{ nombre: " << actual.nombre << ",cuenta: " << actual.cuenta << ", promedio: " << actual.promedio << " }\n";

		alumnosIn.read(reinterpret_cast<char*>(&actual), sizeof(alumnos));
	}

	alumnosIn.close();
}
