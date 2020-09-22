#include "utilerias.h"
#include "ListaEnlazadaSimple.h"
#include "ArbolBinario.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main(){

	 obtenerCantidadRegistros();
	 imprimirCantidadPorTipoPago();

	 ListaSimple ls;

	 ls.cargarDatos(2009, 8, 10);

	 ls.obtenerTotalxMes(2);

	 ls.eliminarDatosMes(9);

	 ArbolBinario arb;

	 arb.agregarArbolBinarioRama();
	 arb.imprimir();

	 _getch();
}