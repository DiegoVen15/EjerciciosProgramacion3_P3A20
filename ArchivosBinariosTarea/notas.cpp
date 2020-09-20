#include "notas.h"
#include <fstream>
#include <iostream>
#include "materias.h"
#include "alumnos.h"
using namespace std;

void agregarNotaMateria() {

	ofstream notasOut("alumnos.dat", ios::out | ios::app | ios::binary);

	if (!notasOut) {

		cout << "Error al abrir archivo\n";
		return;
	}

	notas nuevo;
	cout << "Ingrese el numero de cuenta: ";
	cin >> nuevo.cuentaN;

	cout << "Ingrese el codigo de la materia: ";
	cin >> nuevo.codigoM;

	cout << "Ingrese la nota: ";
	cin >> nuevo.nota;

	notasOut.write(reinterpret_cast<const char*>(&nuevo), sizeof(notas));
	notasOut.close();
}

void listarNotas(int numCuenta) {

	fstream notasInOut("alumnos.dat", ios::in | ios::out | ios::binary);

	if (!notasInOut) {

		cout << "Error al abrir archivo\n";
		return;
	}

	notas lista;

	notasInOut.seekg(numCuenta, ios::beg);

	notasInOut.read(reinterpret_cast<char*>(&lista), sizeof(notas));

	while (!notasInOut.eof()) {

		cout << "Notas{ numero de cuenta: " << lista.cuentaN << ", codigo de materia: " << lista.codigoM << ", nota obtenida: " << lista.nota << " }\n";

		notasInOut.read(reinterpret_cast<char*>(&lista), sizeof(notas));
	}

	notasInOut.close();
}

void actualizarPromedio(int numCuenta) {

	fstream notasOut("alumnos.dat", ios::out | ios::out | ios::binary);

	if (!notasOut) {

		cout << "Error al abrir archivo\n";
		return;
	}

	notas nuevo;
	materias l;
	alumnos a;

	notasOut.seekg(numCuenta, ios::beg);

	notasOut.read(reinterpret_cast<char*>(&nuevo), sizeof(notas));

	a.promedio = nuevo.nota / l.uv;

	notasOut.seekp(numCuenta, ios::beg);

	notasOut.write(reinterpret_cast<char*>(&nuevo), sizeof(notas));

	cout << "Promedio actualizado\n";
	notasOut.close();
}