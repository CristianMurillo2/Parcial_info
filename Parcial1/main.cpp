#include<P1.h>

int main(){
    int*array=arreglo();
    int longitud=tamanoArreglo(array);
    int *tam_mat = new int[(longitud)];
    int *tam_rot = new int[(longitud)];
    dim_rot(array, longitud, tam_mat, tam_rot);
    cout << "Dimensiones de las matrices y cantidad de rotaciones realizadas:" << endl;
    for (int i = 0; i < longitud-1; ++i) {
        cout << tam_mat[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < longitud-1; ++i) {
        cout << tam_rot[i] << " ";
    }
    cout << endl;
    delete[] tam_mat;
    delete[] tam_rot;
    return 0;
}

