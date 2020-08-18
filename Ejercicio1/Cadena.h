#pragma once
#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <conio.h>
#include <cstring>
#include <string>

using namespace std;

class Cadena {

	friend std::ostream& operator<<(std::ostream&, const Cadena&);
	friend Cadena operator+(const Cadena&, const Cadena&);

private:
	const char* c0;
	const char* c3;
	char* c4;
	int tamano = strlen(c0) + strlen(c3.c_str());

public:

	Cadena(void);
	Cadena(const char*, const char*); 
};

#endif // !CADENA_H
