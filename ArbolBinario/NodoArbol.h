#pragma once
#ifndef NODOARBOL_H
#define NODOARBOL_H
struct bin {

	char* nombre;
	NodoArbol* hijoDerecho;
	NodoArbol* hijoIzquierdo;
};

class NodoArbol {

private:
	char* nombre;
	NodoArbol* hijoDerecho;
	NodoArbol* hijoIzquierdo;

public:
	NodoArbol();
	NodoArbol(bin);
	NodoArbol(const char*, NodoArbol*, NodoArbol*);

	void setNombre(const char*);
	void setHijoDerecho(NodoArbol*);
	void setHijoIzquierdo(NodoArbol*);

	char* getNombre(void);
	NodoArbol* getHijoDerecho(void);
	NodoArbol* getHijoIzquierdo(void);

};
#endif // !NODOARBOL_H