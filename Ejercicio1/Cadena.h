#pragma once
#ifndef CADENA_H
#define CADENA_H

#define LIMITE 30
#include <iostream>
#include <conio.h>
#include <cstring>
#include <string>

using namespace std;

class Cadena {

	friend std::ostream& operator<<(std::ostream&, const Cadena&);
	friend Cadena operator+(const Cadena&, const Cadena&);

private:
	const char* cadena;
	int tamano = strlen(cadena);

public:

	Cadena(void);
	Cadena(const char*);

	void setCadena(const char*);

	const char* getCadena(void);

	int strCmp(Cadena);
	string subStr(size_t, size_t);

}