#include <iostream>
#include <cstdlib>
#include<conio.h>
#include<ctime>

using namespace std;

//Definir los prototipos de funcion
void juegoPrincipal(void);
bool esCorrecto(int, int);


int main()
{

	srand(time(NULL));
	juegoPrincipal();
	_getch();
}

void juegoPrincipal() {

	int numeroIndicado; //numero que indique usuario
	int numeroAdivinar; //numero generado
	char respuesta; //opcion de respuesta

	do {

		numeroAdivinar = rand() % 1000 + 1;
		std::cout << "Tengo un numero entre 1 y 1000.\n"
			<< "Lo puedes adivinar?\n"
			<< "Ingresa tu primera opcion: " << endl << "? ";

		cin >> numeroIndicado;

		while (!esCorrecto(numeroAdivinar, numeroIndicado)) {
			cin >> numeroIndicado;
			cout << "Excelente! Has descubierto el numero generado!\n";
			cout << "Deseas volver a jugar (y o n)";
		}

		cout << endl; //aplicar un salto de linea en consola

	} while (respuesta == 'y');
}

bool esCorrecto(int nAdivinacion, int nIndicado) {

	if (nAdivinacion == nIndicado)
		return true;

	if (nIndicado < nAdivinacion)
		cout << "Muy bajo, intentalo de nuevo\n";
	else
		cout << "Muy alto, intentalo de nuevo\n";
	return false;
}