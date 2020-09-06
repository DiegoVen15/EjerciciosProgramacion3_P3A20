#include "EmpresaLista.h"
#include <iostream>
#include <deque>

using namespace std;

empresaLista::empresaLista() : primero(nullptr), ultimo(nullptr)
{}

bool empresaLista::estaVacia() {

	return primero == nullptr;
}

bool empresaLista::agregarEmpleado(int codigo1, char* nombre1, float salario1) {

	empleadoNodo* nuevo = new empleadoNodo(codigo1, nombre1, salario1, nullptr, nullptr);

	if (estaVacia()) {

		primero = nuevo;
		ultimo = nuevo;

	}
	else {


		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);

		ultimo = nuevo;

	}

	return true;
}

bool empresaLista::insertarEmpleado(int codigo1, char* nombre1, float salario1) {

	empleadoNodo* nuevo = new empleadoNodo(codigo1, nombre1, salario1, nullptr, nullptr);

	if (estaVacia()) {

		primero = nuevo;
		ultimo = nuevo;

	}
	else {

		primero->setAnterior(nuevo);
		nuevo->setSiguiente(primero);

		primero = nuevo;
	}
	return true;
}

bool empresaLista::eliminarEmpleado(int codigo1) {

	if (estaVacia()) {

		return;
	}

	empleadoNodo* actual = primero;

	do {

		if (actual->getCodigo() == codigo1) {

			if (actual == primero) {

				primero = actual->getSiguiente();
				delete actual;
				return true;
			}
			else if (actual == ultimo) {

				ultimo = actual->getAnterior();
				delete actual;
				return true;
			}
			else {

				actual->getAnterior()->setSiguiente(actual->getSiguiente());
				actual->getSiguiente()->setAnterior(actual->getAnterior());
				delete actual;
				return true;
			}
		}
		actual = actual->getSiguiente();
	} while (actual != nullptr);

	return false;
}

void empresaLista::actualizarSalarios(float salario1) {

	if (estaVacia()) {

		return;
	}
	else {

		empleadoNodo* actual = primero;

		while (actual != nullptr) {
			if (salario1 > 0 && salario1 < 1) {

				actual->setSalario(actual->getSalario() + actual->getSalario() * salario1);
			}
			else {

				cout << "Salario no valido";
			}
			actual = actual->getSiguiente();
		}
	}
}

void empresaLista::imprimirEmpleados() {

	if (estaVacia())
		return;

	empleadoNodo* actual = primero;

	while (actual != nullptr) {

		cout << "Empleado { codigo: " << actual->getCodigo() << ", nombre: " << actual->getNombre() << ", Salario: " << actual->getSalario() << " }\n";
		actual = actual->getSiguiente();
	}
}