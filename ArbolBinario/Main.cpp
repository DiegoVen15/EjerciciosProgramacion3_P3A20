#include <conio.h>
#include "ArbolBinario.h"
#include <iostream>
using namespace std;
int main()
{

	ArbolBinario arbol;

	arbol.agregarElemento("Julio");
	arbol.agregarElemento("Francis");
	arbol.agregarElemento("Ana");
	arbol.agregarElemento("Xiomara");
	arbol.agregarElemento("Lily");
	arbol.agregarElemento("Yessiel");

	arbol.imprimirArbol();

	cout << "Peso del arbol: " << arbol.obtenerPeso();
	cout << "Altura maxima: " << arbol.obtenerAlturaMaxima();

	arbol.guardarElementos();
	arbol.cargarElementos();

	arbol.esLista();
	_getch();
}