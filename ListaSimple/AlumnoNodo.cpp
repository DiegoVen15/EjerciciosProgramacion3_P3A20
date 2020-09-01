#include "AlumnoNodo.h"

AlumnoNodo::AlumnoNodo(void) : nombre(), nota(-1), siguiente(nullptr)
{}

AlumnoNodo::AlumnoNodo(char* nombre1, float nota1, AlumnoNodo* siguiente1) {

	setNombre(nombre1);
	setNota(nota1);
	setSiguiente(siguiente1);
}

void AlumnoNodo::setNombre(char* nombre1) {

	this->nombre = nombre1;
}

void AlumnoNodo::setNota(float nota1) {

	this->nota = nota1;
}

void AlumnoNodo::setSiguiente(AlumnoNodo* siguiente1) {

	this->siguiente = siguiente1;
}

char* AlumnoNodo::getNombre() {

	return nombre;
}

float AlumnoNodo::getNota() {

	return nota;
}

AlumnoNodo* AlumnoNodo::getSiguiente() {

	return siguiente;
}
