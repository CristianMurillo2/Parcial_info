#include <P1.h>
int *ptr_new_p1(int n)
{
    return new int[n];
}
bool esNumero(char c)
{
    bool s;
    if(c >= '0' && c <= '9'){
        s=true;
    }
    else
        s=false;
    return s;
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
void rotarMatriz90(int **matriz, int tam, int n) {
    for (int r = 0; r < n; ++r) {
        int **temp = new int *[tam];
        for (int i = 0; i < tam; ++i) {
            temp[i] = new int[tam];
        }
        for (int i = 0; i < tam; ++i) {
            for (int j = 0; j < tam; ++j) {
                temp[j][tam - i - 1] = matriz[i][j];
            }
        }
        for (int i = 0; i < tam; ++i) {
            for (int j = 0; j < tam; ++j) {
                matriz[i][j] = temp[i][j];
            }
        }
        for (int i = 0; i < tam; ++i) {
            delete[] temp[i];
        }
        delete[] temp;
    }
}

int *convertirArregloNumerico(char *arreglo)
{
    int longitud = 0;
    int capacidad = 10;
    int* arregloNumerico = new int[capacidad];
    int indice = 0;

    while (*arreglo != '\0') {
        if (esNumero(*arreglo) || *arreglo == '-') {
            int signo = 1;
            if (*arreglo == '-') {
                signo = -1;
                ++arreglo;
            }
            if (indice >= 2 && ((*arreglo - '0') != 1 && (*arreglo - '0') != -1)) {
                cout << "Error: A partir de la posición 2, los números solo pueden ser 1 o -1." << endl;
                delete[] arregloNumerico;
                return nullptr;
            }
            arregloNumerico[indice++] = (*arreglo - '0') * signo;
            if (indice == capacidad) {
                if (capacidad >= INT_MAX / 2) {
                    cout << "Error: El tamaño del arreglo excede el límite." << endl;
                    delete[] arregloNumerico;
                    return nullptr;
                }
                capacidad *= 2;
                int* temp = new int[capacidad];
                for (int i = 0; i < longitud; ++i) {
                    temp[i] = arregloNumerico[i];
                }
                delete[] arregloNumerico;
                arregloNumerico = temp;
            }
            ++longitud;
        } else {
            cout << "Error: La cadena contiene un caracter no permitido." << endl;
            delete[] arregloNumerico;
            return nullptr;
        }
        ++arreglo;
    }
    arregloNumerico[indice] = '\0';
    int* resultado = new int[longitud];
    for (int i = 0; i < longitud; ++i) {
        resultado[i] = arregloNumerico[i];
    }
    delete[] arregloNumerico;

    return resultado;
}

int *arreglo() {
    char entrada[100];
    cout << "Ingrese una cadena de caracteres que represente un arreglo: ";
    cin>>entrada;
    int* arregloNumerico = convertirArregloNumerico(entrada);
    return arregloNumerico;
}

bool comparar(int **a,int **b,int tam_a,int tam_b,int fa,int ca)
{
    int dif_tam = (tam_a != tam_b) ? (tam_a - tam_b) / 2 : 0;
    int f_b = fa - dif_tam;
    int c_b = ca - dif_tam;
    if (f_b >= 0 && f_b < tam_b && c_b >= 0 && c_b < tam_b) {
        return (a[fa][ca] > b[f_b][c_b]);
    }
    return false;
}

int tamanoArreglo(int *arreglo)
{
    int tamano = 0;
    while (arreglo[tamano] != '\0') {
        ++tamano;
    }
    return tamano;
}

void dim_rot(int *array, int longitud, int *&tam_mat, int *&tam_rot)
{
    int n=0;
    int dim = 0;
    int rot = 0;
    int tam_min;
    int f = array[0], c = array[1];

    if (f > c) {
        tam_min = f;
    } else {
        tam_min = c;
    }
    if (tam_min % 2 == 0) {
        tam_min += 1;
    }
    for (int m = 2; m < longitud; ++m) {
        int tam_min_aux=tam_min;
        int **matriz1 = new int *[tam_min_aux];
        int **matriz2 = new int *[tam_min];
        for (int i = 0; i < tam_min; ++i) {
            matriz1[i] = new int[tam_min];
            matriz2[i] = new int[tam_min];
        }
        if (array[m] == 1) {
            tam_mat[dim] = tam_min+2;
            dim++;
            tam_min_aux+=2;
            tam_rot[rot] = 0;
            rot++;
        } else if (array[m] == -1) {
            bool mat = comparar(matriz1, matriz2, tam_min, tam_min, f, c);
            int cant_rot = 0;
            while (mat) {
                rotarMatriz90(matriz2, tam_min,n);
                mat = comparar(matriz1, matriz2, tam_min, tam_min, f, c);
                cant_rot++;
                if (cant_rot < 4 && mat) {
                    tam_min += 2;
                    for (int i = 0; i < tam_min; ++i) {
                        delete[] matriz2[i];
                        matriz2[i] = new int[tam_min];
                    }
                    original_matriz(matriz2, tam_min);
                }
            }
            tam_mat[dim] = tam_min;
            dim++;
            tam_rot[rot] = cant_rot;
            rot++;
        }
        for (int i = 0; i < tam_min; ++i) {
            delete[] matriz1[i];
            delete[] matriz2[i];
        }
        delete[] matriz1;
        delete[] matriz2;
    }


}



