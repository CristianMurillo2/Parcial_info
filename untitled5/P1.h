#ifndef P1_H
#define P1_H
#include <iostream>

using namespace std;
int longitudCad(int *cadena);
int *ptr_new_p1(int n);
bool esNumero(char c);
int* convertirArregloNumerico(char* arreglo);
int *arreglo();
bool comparar(int **a,int **b,int tam_a,int tam_b,int fa,int ca);
int *crearcadena(int n);
int **ptr_new_p2(int n);
void ptr_delete_p1(int *ptr);
void ptr_delete_p2(int **ptr, int n);
void original_matriz(int **matriz, int n);
void print_matriz(int **matriz, int n);
void rotate_matriz(int **matriz, int **rotate_matriz, int n);

#endif // P1_H
