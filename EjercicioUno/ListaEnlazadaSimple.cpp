#include "ListaEnlazadaSimple.h"

#include <iostream>

using namespace std;

ListaSimple::ListaSimple() : primero(nullptr);
{}

void ListaSimple::cargarDatos(int anio, int mesI, int mesF) {

	Nodo* nuevo = new Nodo(anio, mesI, mesF);
	if (mesI < mesF) {

		if( mesI == )
	}
	else {

		cout << "Error en el ingreso de los meses";
	}
}

double ListaSimple::obtenerTotalxMes(int mes) {

	cout << 
}

void ListaSimple::eliminarDatosMes(int mes) {

}