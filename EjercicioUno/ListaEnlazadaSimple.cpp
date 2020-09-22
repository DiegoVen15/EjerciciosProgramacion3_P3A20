#include "ListaEnlazadaSimple.h"

#include <iostream>

using namespace std;

ListaSimple::ListaSimple() : primero(nullptr)
{}

void ListaSimple::cargarDatos(int anio, int mesI, int mesF) {

	Nodo* nuevo = new Nodo(anio, mesI, mesF);
	Nodo* actual = primero;
	if (mesI < mesF) {
		while (actual->getSiguiente() != nullptr) {
			actual = actual->getSiguiente();
		}

		if (anio == actual->getYear() && mesI == actual->getMonth() && mesF == actual->getMonth()) {
				actual->setSiguiente(nuevo);
		}
		
		cout << "Nodo Agregado";
	}
	else {
		cout << "Error en el ingreso de los meses";
	}
}

double ListaSimple::obtenerTotalxMes(int mes) {

	Nodo* actual = primero;
	double cant = 0;

	while (actual != nullptr) {

		cant += actual->getTotal();
		actual = actual->getSiguiente();
	}
	
	cout << "\n";
}

void ListaSimple::eliminarDatosMes(int mes) {

	Nodo* actual = primero;
	Nodo* anterior = nullptr;

	while (actual != nullptr)
	{

		if (actual->getMonth() == mes)
		{
			if (actual == primero)
			{
				primero = actual->getSiguiente();
				delete actual;
			}
			else
			{
				anterior->setSiguiente(actual->getSiguiente());
				delete actual;
			}

			cout << "Nodo eliminado!\n";
			return;
		}
		else
		{
			anterior = actual;
			actual = actual->getSiguiente();
		}

		actual = actual->getSiguiente();
	}

	cout << "Nodo no existe. Imposible eliminarlo\n";
}