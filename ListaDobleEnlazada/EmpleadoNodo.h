#pragma once
#ifndef EMPLEADONODO_H
#define EMPLEADONODO_H

class empleadoNodo {

private:
	int codigo;
	char* nombre;
	float salario;
	empleadoNodo* anterior;
	empleadoNodo* siguiente;

public:
	empleadoNodo(void);
	empleadoNodo(int, char*, float, empleadoNodo*, empleadoNodo*);

	void setCodigo(int);
	int getCodigo();

	void setNombre(char*);
	char* getNombre();

	void setSalario(float);
	float getSalario();

	void setAnterior(empleadoNodo*);
	empleadoNodo* getAnterior();

	void setSiguiente(empleadoNodo*);
	empleadoNodo* getSiguiente();
};
#endif // !EMPLEADONODO_H
