#pragma once
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoArbol.h"
#include <fstream>
#include<iostream>
using namespace std;


class ArbolBinario
{
private:
	NodoArbol* raiz;

public:
	ArbolBinario();

	void agregarElemento(const char*);
	//funcion recursiva
	NodoArbol* agregarAux(NodoArbol*, const char*);

	void imprimirArbol();
	void imprimirAux(NodoArbol*);

	int obtenerPeso();
	int pesoTotal(NodoArbol*);
	int obtenerAlturaMaxima();
	int alturaTotal(NodoArbol*);
	void guardarElementos();
	void guardarTotal(NodoArbol*, ofstream*);
	void cargarElementos();

	void cargarTotal(NodoArbol*, ifstream*);
	bool esLista();
	bool esListaEnlazada(NodoArbol*);

};


#endif // !ARBOLBINARIO_H