#include "ArbolBinario.h"
#include "utilerias.h"
#include <iostream>
#include <fstream>

using namespace std;


ArbolBinario::ArbolBinario() : raiz(nullptr)
{}


void ArbolBinario::agregarElemento(const char* nombre1)
{

	raiz = agregarRama(raiz, nombre1);

}

NodoArbol* ArbolBinario::agregarRama(NodoArbol* raiz1, const char* nombre1)
{

	if (raiz1 == nullptr)
	{
		NodoArbol* nuevo = new NodoArbol(nombre1, nullptr, nullptr);
		raiz1 = nuevo;

	}
	else if (strcmp(nombre1, raiz1->getNombre()) == 0) {
		return raiz1;
	}
	else if (strcmp(nombre1, raiz1->getNombre()) > 0)
		raiz1->setHijoDerecho(agregarRama(raiz1->getHijoDerecho(), nombre1));
	else if (strcmp(nombre1, raiz1->getNombre()) < 0)
		raiz1->setHijoIzquierdo(agregarRama(raiz1->getHijoIzquierdo(), nombre1));

	return raiz1;
}

void ArbolBinario::imprimir()
{
	imprimirRama(raiz);
}

void ArbolBinario::imprimirRama(NodoArbol* raiz1)
{

	if (raiz1 == nullptr) {
		return;
	}
	cout << "[" << raiz1->getNombre() << " ]\n ";
	imprimirRama(raiz1->getHijoIzquierdo());
	imprimirRama(raiz1->getHijoDerecho());
}

void ArbolBinario::agregarArbolBinarioRama()
{
	ifstream obtener("datab.bin", ios::in | ios::binary);

	if (!obtener)
	{
		cout << "Error al abrir archivo\n";
		return;
	}

	//posicionarse al inicio del archivo
	obtener.seekg(0, ios::beg);

	registro actual;
	string apellido;
	//leer el primer registro
	obtener.read(reinterpret_cast<char*>(&actual), sizeof(registro));

	while (!obtener.eof())
	{
		apellido = actual.lastname;
		agregarElemento(apellido.c_str());
		obtener.read(reinterpret_cast<char*>(&actual), sizeof(registro));
	}
	obtener.close();
}