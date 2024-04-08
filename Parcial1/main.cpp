#include<P1.h>

int main(){
    int*array=arreglo();
    int longitud=tamanoArreglo(array);
    int *tam_mat = new int[longitud-1];
    int *tam_rot = new int[longitud-1];
    dim_rot(array, longitud, tam_mat, tam_rot);

    cout << "Dimensiones de las matrices y cantidad de rotaciones realizadas:" << endl;
    for (int i = 0; i < longitud; ++i) {
        cout <<tam_mat[i]<<" ";
        cout<<tam_rot[i]<<" ";
    delete[] array;
    delete[] tam_mat;
    delete[] tam_rot;
    return 0;
}
}
