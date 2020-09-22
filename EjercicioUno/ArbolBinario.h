#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoArbol.h"

#include <fstream>
#include <iostream>

class ArbolBinario {

private:

	NodoArbol* raiz;

	void imprimirRama(NodoArbol*);
	NodoArbol* agregarRama(NodoArbol*, const char*);
	
public:

	ArbolBinario();
	void agregarArbolBinarioRama();

	void agregarElemento(const char*);

	void imprimir();
};

#endif // !ARBOLBINARIO_H#pragma once
