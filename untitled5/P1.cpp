#include <P1.h>
int *ptr_new_p1(int n)
{
    return new int[n];
}

void ptr_delete_p2(int *ptr)
{
    delete [] ptr;
}

int **ptr_new_p2(int n)
{
    int **ptr = new int* [n];
    for(int i=0;i<n;i++){
        ptr[i]= ptr_new_p1(n);
    }
    return ptr;
}

void ptr_delete_p2(int **ptr, int n)
{
    for(int i=0;i<n;i++) ptr_delete_p2(ptr[i]);
    delete[] ptr;
}


void original_matriz(int **matriz, int n)
{
    int cont=1;
    for(int fil=0;fil<n;fil++){
        for(int col=0;col<n;col++){
            if (fil==n/2 && col==n/2) {
                matriz[fil][col] = 0;
            }
            else {
                matriz[fil][col] = cont++;
        }
    }
}
}

void print_matriz(int **matriz, int n)
{
    for(int fil=0; fil<n;fil++){
        for(int col=0;col<n;col++) cout<< matriz[fil][col]<<'\t';
        cout << endl <<endl;
    }
}

void rotate_matriz(int **matriz, int **rotate_matriz, int n)
{
    for(int fil=0; fil<n;fil++){
        for(int col=0;col<n;col++) rotate_matriz[fil][col]=matriz[(n-1)-col][fil];

    }
}

