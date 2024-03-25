#ifndef P1_H
#define P1_H
#include <iostream>

using namespace std;

int *ptr_new_p1(int n);
int **ptr_new_p2(int n);
void ptr_delete_p1(int *ptr);
void ptr_delete_p2(int **ptr, int n);
void original_matriz(int **matriz, int n);
void print_matriz(int **matriz, int n);
void rotate_matriz(int **matriz, int **rotate_matriz, int n);

#endif // P1_H
