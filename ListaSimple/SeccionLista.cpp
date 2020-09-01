#include "SeccionLista.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

SeccionLista::SeccionLista() : primero(nullptr)
{}

bool SeccionLista::estaVacia() {

	return primero == nullptr;
}

void SeccionLista::agregarAlumno(char* nombre1, float nota1) {

	AlumnoNodo* nuevo = new AlumnoNodo(nombre1, nota1, nullptr);

	if (estaVacia()) {

		primero = nuevo;
	}
	else {

		AlumnoNodo* actual = primero;
		bool flag = true;

		while (actual->getSiguiente() != nullptr) {
			if ((strcmp(nombre1, actual->getNombre()) > 0) && (strcmp(actual->getSiguiente()->getNombre(), nombre1) > 0)) {
				nuevo->setSiguiente(actual->getSiguiente());
				actual->setSiguiente(nuevo);
				flag = false;
			}
			else {
				actual = actual->getSiguiente();
			}
		}
		if (flag) {

			if (actual->getNombre() == primero->getNombre()) {
				if (strcmp(actual->getNombre(), nombre1) > 0) {
					nuevo->setSiguiente(actual);
					primero = nuevo;
				}
				else {
					actual->setSiguiente(nuevo);
				}
			}
			else
				actual->setSiguiente(nuevo);
		}

	}
}

void SeccionLista::listarSeccion() {

	AlumnoNodo* actual = primero;


	while (actual != nullptr) {

		cout << "Nombre: " << actual->getNombre() << "\nNota: " << actual->getNota() << "\n";
		actual = actual->getSiguiente();
	}

	cout << "\n";
}

int SeccionLista::cantidadAprobados() {

	AlumnoNodo* actual = primero;
	int aprobados = 0;
	while (actual != nullptr) {

		if (actual->getNota() > 70) {
			aprobados++;
			actual = actual->getSiguiente();
		}
		else {
			actual = actual->getSiguiente();
		}
	}

	return aprobados;
}