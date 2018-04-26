#include "Ordenador.h"
#include <chrono>
#define tam 1000000

int main () {
  Ordenador o;
  int * vech =  o.creaVec(tam);
  int * vecq =  o.creaVec(tam);
  int * vecr =  o.creaVec(tam);

  std::cout << "HeapSort" << endl;
  auto t1 = std::chrono::high_resolution_clock::now();
  //o.printVec(vech, tam);
  o.heapsort(vech, tam);
  //o.printVec(vech, tam);
  auto t2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> fp_ms1 = (t2 - t1)/1000;
  std::cout << "Tarda " << fp_ms1.count() << " secs. " << std::endl << std::endl;

  std::cout << "QuickSort" << std::endl;
  auto t3 = std::chrono::high_resolution_clock::now();
  //o.printVec(vecq, tam);
  o.quicksort(vecq, tam);
  //o.printVec(vecq, tam);
  auto t4 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> fp_ms2 = (t4 - t3)/1000;
  std::cout << "Tarda " << fp_ms2.count() << " secs. " << std::endl << std::endl;

  std::cout << "RadixSort" << std::endl;
  auto t5 = std::chrono::high_resolution_clock::now();
  //o.printVec(vecr, tam);
  o.radixsort(vecr, tam);
  //o.printVec(vecr, tam);
  auto t6 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> fp_ms3 = (t6 - t5)/1000;
  std::cout << "Tarda " << fp_ms3.count() << " secs. " << std::endl << std::endl;

  o.printVec(vecr, tam);
  o.mediana(vecr, tam);
  o.printVec(vecr, tam);

  return 0;
}
