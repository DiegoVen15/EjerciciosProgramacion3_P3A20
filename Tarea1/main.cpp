#include <iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
using namespace std;

int main() {

	int num = 0;
	int numFac = 0;
	int op = 0;
	long numB = 0;
	long Bin = 1;
	long resi = 0;
	int numDec = 0;
	int cont = 0;
	int numFibo = 0;
	int fibo = 0;
	int fibo1 = 0;
	int fibo2 = 1;
	int numF1 = 1;

	do {
		cout << " MENU PRINCIPAL\n"
			<< "1. Decomposicion de numero en factores primos\n"
			<< "2. Convertir numero a su representacion en binario\n"
			<< "3. Sucesion Fibonacci\n"
			<< "4. Salir\n"
			<< "Ingrese la opcion: " << endl;
		cin >> num;

		switch (num) {

		case 1:
			do {
				cout << "Ingresar el numero:\n";
				cin >> numFac;
				printf("%d = ", numFac);

				for (int i = 2; numFac > 1; i++) {
					while (numFac % i == 0) {
						printf("%d ", i);
						numFac = numFac / i;
					}
				}
				cout << endl;
				cout << "Desea ingresar otro numero? \n1. Si\n2.No\nIngrese la opcion: ";
				cin >> op;
			} while (op == 1);
			break;

		case 2:

			cout << "Ingresar el numero binario: ";
			cin >> numB;

			if (numB == 0) {

				cout << "El numero en decimal es: 0 " << endl;
				break;
			}

			while (numB != 0) {  
				
				resi = 0;
				resi = Bin * (numB % 10);
				numDec += resi;
				Bin = Bin * 2;
				numB = numB / 10;
			}

			printf("El numero en decimal es: %d", numDec);
			cout << endl;

			numB = 0;
			Bin = 1;
			resi = 0;
			numDec = 0;

			break;

		case 3:

			cout << "Ingrese la cantidad de numeros a observar: ";
			cin >> numFibo;

			while (numF1 <= numFibo) {
				cout << fibo1 << endl;
				fibo = fibo1 + fibo2;
				fibo1 = fibo2;
				fibo2 = fibo;
				numF1++;
			}

			numF1 = 1;
			fibo = 0;
			fibo1 = 0;
			fibo2 = 1;
				
			break;

		case 4:
			break;
		}

	} while (num < 4);
	_getch();
}