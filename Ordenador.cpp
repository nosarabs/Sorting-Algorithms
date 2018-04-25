#include "Ordenador.h"

Ordenador::Ordenador() {

}

Ordenador::~Ordenador() {

}

int * Ordenador::creaVec (int tam) {
  //CREA VECTOR
  //LLENA VECTOR DE NUMEROS POSITIVOS Y NEGATIVOS ALEATORIOS ENTRE -10 Y 10
  int * vec = new int[tam];
  for (int i = 0; i < tam; ++i) {
    vec[i] = (rand() % 201)-100;
  }
  return vec;
}

void Ordenador::printVec (int * vec, int tam) {
  //IMPRIME VECTOR
  for (int i = 0; i < tam; ++i) {
    cout << vec[i] << " | ";
  }
  cout << endl << endl;
}

void Ordenador::seleccion(int * arreglo, int tamano){
  if (tamano > 1) {
    int min;
    int aux;
    int i;
    for (i = 0; i < tamano - 1; ++i) {
      min = i;
      for (int j = i + 1; j < tamano; ++j) {
        if (arreglo[j] < arreglo[min]) {
          min = j;
        }
      }
      aux = arreglo[i];
      arreglo[i] = arreglo[min];
      arreglo[min] = aux;
    }
  }
}

void Ordenador::insercion(int * arreglo, int tamano){
  if (tamano > 1) {
    int key;
    int i;
    for (int j = 1; j < tamano; ++j) {
      key = arreglo[j];
      i = j - 1;
      while (i >= 0 && arreglo[i] > key) {
        arreglo[i+1] = arreglo[i];
        --i;
      }
      arreglo[i+1] = key;
    }
  }
}

void Ordenador::mergesort(int * arreglo, int tamano) {
  mergesortx(arreglo, 0, tamano-1);
}

void Ordenador::mergesortx(int * arreglo, int l, int r) {
  if (l < r) {
    int m = floor( ( l + (r-1) )/2 );

    mergesortx(arreglo, l, m);
    mergesortx(arreglo, m+1, r);
    merge(arreglo, l, m, r);
  }
}

void Ordenador::merge(int * arreglo, int l, int m, int r) {

  int nL = m - l + 1;
  int nR = r - m;

  int L[nL];
  int R[nR];

  int i, j, k;

  for (i = 0; i < nL; ++i) {
    L[i] = arreglo[l+i];
  }
  for (j = 0; j < nR; ++j) {
    R[j] = arreglo[m+1+j];
  }

  //Se reinician los indices
  i = 0;
  j = 0;
  k = l;

  while (i < nL && j < nR) {
    if (L[i] <= R[j]) {
      arreglo[k] = L[i];
      ++i;
    } else {
      arreglo[k] = R[j];
      ++j;
    }
    ++k;
  }

  //Pone los elementos restantes en el arreglo
  while (i < nL) {
    arreglo[k] = L[i];
    ++i;
    ++k;
  }
  while (j < nR) {
    arreglo[k] = R[j];
    ++j;
    ++k;
  }
}

int Ordenador::mediana(int * arreglo, int tamano){
  int mediana, x, aux;
  int k = tamano/2;
  int l = 0;
  int r = tamano-1;

  // En caso de que el arreglo este ordenado (peor caso) se hace lo siguiente:
  x = rand() % tamano;
  aux = arreglo[r];
  arreglo[r] = arreglo[x];
  arreglo[x] = aux;
  int i = partition(arreglo, l, r);

  /*
  Utiliza el metodo partition para encontrar la mediana.
  Partition devuelve la posicion en la que se encuentra el pivote,
  Este metodo pregunta si el pivote es mayor o menor que la posicion de la mediana,
  Que es n/2, y procede a llamar nuevamente a partition pero solamente en el lado del
  arreglo el cual contiene a la mediana.
  */

  while (k != i) {
    if (i < k) {
      i = partition(arreglo, i+1, r);
    }
    if (i > k) {
      i = partition(arreglo, l, i-1);
    }
  }
  mediana = arreglo[k];
  // Para probar que el numero obtenido es realmente la mediana.
  // cout << mediana << endl;
  // cout << arreglo[tamano/2] << endl;
  return mediana;
}

void Ordenador::heapsort(int * arreglo, int tamano) {
  //Monticuliza
  for (int i = (tamano/2)-1; i >= 0; --i) {
    heapify(arreglo, tamano, i);
  }
  //Sacadas
  for (int j = tamano-1; j >= 0; --j) {
    int aux = arreglo[0];
    arreglo[0] = arreglo[j];
    arreglo[j] = aux;

    heapify(arreglo, j, 0);
  }
}

void Ordenador::heapify(int * arreglo, int tamano, int i) {
  /*
  Este algoritmo se encarga de mantener la condicion de que cada padre debe ser
  mayor que ambos de sus hijos, por medio de la monticularizacion (que son basicamente intercambios)
  de manera recursiva, lo que permite que el arbol se mantenga ordenado.
  */
  
  int max;
  int l = left(i);
  int r = right(i);

  if (l < tamano && arreglo[l] > arreglo[i]) {
    max = l;
  } else {
    max = i;
  }
  if (r < tamano && arreglo[r] > arreglo[max]) {
    max = r;
  }
  if (max != i) {
    int aux = arreglo[i];
    arreglo[i] = arreglo[max];
    arreglo[max] = aux;

    heapify(arreglo, tamano, max);
  }

}

int Ordenador::left(int i) {
  return (2*i)+1;
}

int Ordenador::right(int i) {
  return (2*i)+2;
}

void Ordenador::quicksort(int * arreglo, int tamano) {
  quicksortx(arreglo, 0, tamano-1);
}

void Ordenador::quicksortx(int * arreglo, int l, int r) {
  /*
  Despues de que se encuentra la posicion del pivote devuelta por partition,
  se llama al algoritmo Quick Sort con el subarreglo del lado derecho del
  pivote y tambien con el subarreglo del lado izquierdo de este.
  Como Quick S\ort utiliza el metodo de divide y venceras, lo anterior
  se repite de manera recursiva para ordenar todo el arreglo.
  */

  if (l < r) {
    int m = partition(arreglo, l, r);
    quicksortx(arreglo, l, m-1);
    quicksortx(arreglo, m+1, r);
  }
}

int Ordenador::partition(int * arreglo, int l, int r) {

  /*
  Este metodo simplemente lo que hace es colocar todos los elementos mayores al pivote al lado
  derecho de el, y todos los menores al lado izquierdo. Como el profesor sugiere hacer esto es revisando
  ambos lados del arreglo al mismo tiempo, es decir con el indice j en el ultimo elemento, y el indice i
  en el primero, y avanzar j hasta que i se detenga. Esto me presento problemas por lo que encontre en la literatura
  una manera mas sencilla y eficiente de hacerla, la cual toma el mismo concepto pero empezando con los indices
  en el primero (i) y en el segundo (j), avanzar con el indice j e itercambiar cuando este sea menor a i.
  */

  int p = arreglo[r];
  int i = l - 1;
  int j;

  for (j = l; j <= r - 1; ++j) {
    if (arreglo[j] <= p) {
      ++i;
      int aux1 = arreglo[i];
      arreglo[i] = arreglo[j];
      arreglo[j] = aux1;
    }
  }

    int aux2 = arreglo[i+1];
    arreglo[i+1] = arreglo[r];
    arreglo[r] = aux2;

  return i+1;
}

int Ordenador::getMax (int * arreglo, int tamano) {
  /*
  Busca el numero mas grande del arreglo para luego
  contar cuantos digitos tiene y saber la cantidad de
  veces que se va a hacer un ciclo.
  */
  int max = arreglo[0];
  for (int i = 0; i < tamano; ++i) {
    if (arreglo[i] > max) {
      max = arreglo[i];
    }
  }
  return max;
}

void Ordenador::fix (int * arreglo,int tamano, bool x) {
  /*
  Como el arreglo puede tener numeros negativos, hay que encontrar
  una forma que el algoritmo continue funcionando.
  Hay diferentes maneras para resolver este problema,
  yo lo resolvi de la siguiente manera:

  Primero busque el elemento mas pequenño del arreglo.
  Pregunto si este es negativo, si lo es lo paso a positivo
  Si no lo fuera no seria necesario hacer este proceso, pero
  de igual manera lo hago para poder generalizar el problema.
  Ya pasado a positivo, sumo este numero a todos los numeros del
  arreglo, convirtiendolos todos en positivos, con el menor
  siendo 0.

  Luego se ordena normalmente.

  El parametro booleano que tiene este metodo, indica
  si es la primera o la segunda vez que se llama a este metodo.
  Si es la primera se hace todo lo explicado anteriormente, pero
  si es la segunda se resta el numero menor que ya se habia encontrado,
  y se le resta a todos los numeros del arreglo ya orenado.
  Devolviendolo asi a sus valores originales.
  */

  int min;
  if (x) {
    min = arreglo[0];
    for (int i = 0; i < tamano; ++i) {
      if (arreglo[i] < min) {
        min = arreglo[i];
      }
    }
    if (min < 0) {
      min *= -1;
    }
    for (int j = 0; j < tamano; ++j) {
      arreglo[j] += min;
    }
    this->min = min;
  } else {
    for (int k = 0; k < tamano; ++k) {
      arreglo[k] -= this->min;
    }
  }
}

void Ordenador::radixsort(int * arreglo, int tamano) {
  fix(arreglo, tamano, true);
  int max = getMax(arreglo, tamano);

  /*
  Cuando ya se encontro el mayor numero del arreglo,
  se puede encontrar cuantos digitos tiene siguiendo este patron:
  num: 12345
  5 es 12345 % 10
  4 es 12345 / 10 % 10
  3 es 12345 / 100 % 10
  2 es 12345 / 1000 % 10
  1 es 12345 / 10000 % 10
  Es decir num / 10^{i} % 10
  Con i = la posicion del digito que se quiere aislar
  empezando con el menos significativo siendo 0.
  Como esto se puede generalizar, se puede poner dentro
  de un for, y llamar al metodo countsort solamente
  la cantidad necesaria de veces.
  */

  for (int pos = 1; max/pos > 0; pos *= 10) {
    countsort(arreglo, tamano, pos);
  }

  fix(arreglo, tamano, false);
}

void Ordenador::countsort(int * arreglo, int tamano, int pos) {

  // Crea 2 hisogramas vacios.
  int histo[tamano];
  int histoAcu[tamano];

  for (int k = 0; k < tamano; ++k) {
    histoAcu[k] = 0;
    histo[k] = 0;
  }

  /*
  Esto llena el histograma contador para saber cuantas
  ocurrencias de cada elemento existen en el arreglo.
  Se utiliza lo explicado en Radix Sort para saber la posicion
  del digito que se quiera evaloar, siendo pos 10^i
  */

  for (int i = 0; i < tamano; ++i) {
    histoAcu[(arreglo[i]/pos)%10]++;
  }

  /*
  Luego en ese mismo arreglo se acumula en cada espacio del arreglo
  la suma de las posiciones anteriores y ella misma.
  */

  for (int i = 1; i < tamano; ++i) {
    histoAcu[i] += histoAcu[i-1];
  }

  /*
  Despues se empieza a leer el arreglo original
  desde la ultima posicion es hasta la primera.
  Se toma el digito aislado por el que va.
  Se le resta 1 ya que se va a utilizar como indice en el histograma final.
  En este histograma final se pone el dato que se encontraba en arreglo[i].
  Por ultimo se le resta 1 al numero que se encontraba en la posicion
  descrita en el histograma acumulativo.
  */

  for (int i = tamano - 1; i >= 0; --i) {
    histo[ histoAcu[ (arreglo[i]/pos) % 10]-1] = arreglo[i];
    histoAcu[(arreglo[i]/pos)%10]--;
  }

  // Se copia el histograma final en el arreglo original.

  for (int i = 0; i < tamano; i++) {
    arreglo[i] = histo[i];
  }
}
