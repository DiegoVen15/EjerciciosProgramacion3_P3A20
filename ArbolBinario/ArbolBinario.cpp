#include "ArbolBinario.h"

#include <iostream>
#include <fstream>
using namespace std;

using std::cout;

ArbolBinario::ArbolBinario() : raiz(nullptr)
{}

void ArbolBinario::agregarElemento(const char* _nombre)
{

	raiz = agregarAux(raiz, _nombre);

}

NodoArbol* ArbolBinario::agregarAux(NodoArbol* _raiz, const char* _nombre)
{

	if (_raiz == nullptr)
	{
		NodoArbol* nuevo = new NodoArbol(_nombre, nullptr, nullptr);
		_raiz = nuevo;
	}
	else if (strcmp(_nombre, _raiz->getNombre()) > 0)
		_raiz->setHijoDerecho(agregarAux(_raiz->getHijoDerecho(), _nombre));
	else if (strcmp(_nombre, _raiz->getNombre()) < 0)
		_raiz->setHijoIzquierdo(agregarAux(_raiz->getHijoIzquierdo(), _nombre));

	return _raiz;
}

void ArbolBinario::imprimirArbol()
{
	imprimirAux(raiz);
}

void ArbolBinario::imprimirAux(NodoArbol* _raiz)
{

	if (_raiz == nullptr)
		return;

	cout << "[ " << _raiz->getNombre() << " ] ";
	imprimirAux(_raiz->getHijoIzquierdo());
	imprimirAux(_raiz->getHijoDerecho());
}

int ArbolBinario::obtenerPeso() {

	return pesoTotal(raiz);
}

int ArbolBinario::pesoTotal(NodoArbol* x) {

	int a = 0, b = 0;

	if (x->getHijoIzquierdo() != nullptr) {

		a = pesoTotal(x->getHijoIzquierdo());

	}
	if (x->getHijoDerecho() != nullptr) {

		b = pesoTotal(x->getHijoDerecho());
	}
	int t = a + b;
	
	return t + 1;
}

int ArbolBinario::obtenerAlturaMaxima() {

	return alturaTotal(raiz);
}

int ArbolBinario::alturaTotal(NodoArbol* x) {

	int a = 0, b = 0;

	if (x->getHijoIzquierdo() != nullptr) {

		a = pesoTotal(x->getHijoIzquierdo());
	}
	if (x->getHijoDerecho() != nullptr) {

		b = pesoTotal(x->getHijoDerecho());
	}

	if (a > b) {

		return a + 1;
	}
	else if (a < b) {

		return b + 1;
	}
	else if (a == b) {

		return a;
	}
}

void ArbolBinario::guardarElementos() {

	char elementos[] = "elementos.dat";

	ofstream elementosOut;
	elementosOut.open(elementos, ios::out | ios::end | ios::binary);

	if (!elementosOut) {

		cout << "Error al intentar abrir archivo\n";
		return;
	}

	guardarTotal(raiz, &elementosOut);

	elementosOut.close();
}

void ArbolBinario::guardarTotal(NodoArbol* x, ofstream* elementosOut)
{
	NodoArbol* dos;
	dos->setNombre("Nulo");
	bin agregar;
	if (x->getHijoDerecho() == nullptr)
		agregar.hijoDerecho = dos;
	else
		agregar.hijoDerecho = x->getHijoDerecho();


	if (x->getHijoIzquierdo() == nullptr)
		agregar.hijoIzquierdo = dos;
	else
		agregar.hijoIzquierdo = x->getHijoIzquierdo();


	agregar.nombre = x->getNombre();
	(*elementosOut).write(reinterpret_cast<const char*>(&agregar), sizeof(bin));

	if (x->getHijoDerecho() != nullptr) {

		guardarTotal(x->getHijoDerecho(), elementosOut);
	}
	if (x->getHijoIzquierdo() != nullptr) {

		guardarTotal(x->getHijoIzquierdo(), elementosOut);
	}
}

void ArbolBinario::cargarElementos() {

	char elementos[] = "elementos.dat";

	ifstream elementosIn;
	elementosIn.open(elementos, ios::in | ios::binary);

	NodoArbol* uno;
	raiz = uno;

	if (!elementosIn) {

		cout << "Error al intentar abrir archivo\n";
		return;
	}

	while (!elementosIn.eof()) {

	}

	cargarTotal(raiz, &elementosIn);

	elementosIn.close();
}

void ArbolBinario::cargarTotal(NodoArbol* x, ifstream* elementosIn) {

	bin agregar;
	bin hijo1;
	bin hijo2;
	(*elementosIn).read(reinterpret_cast<char*>(&agregar), sizeof(bin));
	(*elementosIn).read(reinterpret_cast<char*>(&hijo1), sizeof(bin));
	(*elementosIn).read(reinterpret_cast<char*>(&hijo2), sizeof(bin));
	x = new NodoArbol(agregar);
	if (hijo1.nombre == "Nulo")
		x->setHijoDerecho(nullptr);
	else {
		NodoArbol* dere;
		dere = new NodoArbol(hijo1);
		x->setHijoDerecho(dere);
		cargarTotal(dere, elementosIn);
	}

	if (hijo2.nombre == "Nulo")
		x->setHijoIzquierdo(nullptr);
	else {
		NodoArbol* izq;
		izq = new NodoArbol(hijo2);
		x->setHijoIzquierdo(izq);
		cargarTotal(izq, elementosIn);
	}
}

bool ArbolBinario::esLista() {

	esListaEnlazada(raiz);

	if (esListaEnlazada() == true) {

		cout << "Si se considera como una lista enlazada";
		return true;
	}
	else {
		cout << "No es una lista enlazada";
		return false;
	}
}

bool ArbolBinario::esListaEnlazada(NodoArbol* bin) {

	if (bin != nullptr && raiz != nullptr) {
		do {
			if (raiz->getHijoIzquierdo() == nullptr && raiz->getHijoDerecho() != nullptr) {

				return true;
			}
			else {

				return false;
			}

			esListaEnlazada(bin->getHijoDerecho());
			esListaEnlazada(bin->getHijoIzquierdo());
		} while (bin != nullptr);

		do {
			if (raiz->getHijoDerecho() == nullptr && raiz->getHijoIzquierdo() != nullptr) {

				return true;
			}
			else {

				cout << "No es una lista enlazada";
				return false;
			}
			esListaEnlazada(bin->getHijoDerecho());
			esListaEnlazada(bin->getHijoIzquierdo());
		} while (bin != nullptr);
	}
}