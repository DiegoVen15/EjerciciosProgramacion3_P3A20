#include "EmpleadoNodo.h"

empleadoNodo::empleadoNodo() : codigo(-1), nombre(), salario(-1), anterior(nullptr), siguiente(nullptr)
{}

empleadoNodo::empleadoNodo(int codigo1, char* nombre1, float salario1, empleadoNodo* anterior1, empleadoNodo* siguiente1) {

	setCodigo(codigo1);
	setNombre(nombre1);
	setSalario(salario1);
	setAnterior(anterior1);
	setSiguiente(siguiente1);
}

void empleadoNodo::setCodigo(int codigo1) {

	this->codigo = codigo1;
}

void empleadoNodo::setNombre(char* nombre1) {

	this->nombre = nombre1;
}

void empleadoNodo::setSalario(float salario1) {

	this->salario = salario1;
}

void empleadoNodo::setSiguiente(empleadoNodo* siguiente1) {

	this->siguiente = siguiente1;
}

void empleadoNodo::setAnterior(empleadoNodo* anterior1) {

	this->anterior = anterior1;
}

int empleadoNodo::getCodigo() {

	return codigo;
}

char* empleadoNodo::getNombre() {

	return nombre;
}

float empleadoNodo::getSalario() {

	return salario;
}

empleadoNodo* empleadoNodo::getAnterior() {

	return anterior;
}

empleadoNodo* empleadoNodo::getSiguiente() {

	return siguiente;
}