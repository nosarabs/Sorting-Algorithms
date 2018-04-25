#ifndef _CLASE_ORDENADOR
#define _CLASE_ORDENADOR
#include <iostream> //cout
#include  <cstdlib> //random
#include <math.h> //floor

using namespace std;


class Ordenador {

	private:

	void merge(int * arreglo, int l, int m, int r);
	void mergesortx(int * arreglo, int l, int r);

	void heapify(int * arreglo, int tamano, int i);
	int left(int i);
	int right(int i);

	int partition(int * arreglo, int l, int r);
	void quicksortx(int * arreglo, int l, int r);

	void countsort(int * arreglo, int tamano, int i);
	void fix(int * arreglo,int tamano, bool x);
	int getMax(int * arreglo, int tamano);
	int min;


	public:

	Ordenador();
	~Ordenador();

	void seleccion(int * arreglo, int tamano);
	void insercion(int * arreglo, int tamano);
	void mergesort(int * arreglo, int tamano);
	void heapsort(int * arreglo, int tamano);
	void quicksort(int * arreglo, int tamano);
	void radixsort(int * arreglo, int tamano);
	int mediana(int * arreglo, int tamano);

	int * creaVec (int);
	void printVec (int *, int);
};
#endif
