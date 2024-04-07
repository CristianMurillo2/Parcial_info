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


int longitudCad(int *cadena)
{
    int longitud=0;
    while (cadena[longitud]!='\0'){
        longitud++;
    }
    return longitud;
}

bool esNumero(char c)
{
    return (c >= '0' && c <= '9');
}

int *convertirArregloNumerico(char *arreglo)
{
    int longitud = 0;
    int capacidad = 10;
    int* arregloNumerico = new int[capacidad];
    int indice = 0;

    while (*arreglo != '\0') {
        if (esNumero(*arreglo)) {
            arregloNumerico[indice++] = *arreglo - '0';
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
        } else if (*arreglo == '-') {
            arregloNumerico[indice++] = -1;
            ++arreglo;
            if (*arreglo != '1' && *arreglo != '0') {
                cout << "Error: La cadena contiene un formato incorrecto." << endl;
                delete[] arregloNumerico;
                return nullptr;
            }
        } else if (*arreglo != ' ') {
            cout << "Error: La cadena contiene un caracter no permitido." << endl;
            delete[] arregloNumerico;
            return nullptr;
        }
        ++arreglo;
    }
    int* resultado = new int[longitud];
    for (int i = 0; i < longitud; ++i) {
        resultado[i] = arregloNumerico[i];
    }
    delete[] arregloNumerico;

    return resultado;
}

int *arreglo()
{
    char entrada[100];
    cout << "Ingrese una cadena de caracteres que represente un arreglo: ";
    cin.getline(entrada, sizeof(entrada));
    int* arregloNumerico = convertirArregloNumerico(entrada);
    return arregloNumerico;
}

bool comparar(int **a,int **b,int tam_a,int tam_b,int fa,int ca)
{
    short int dif_tam=0,fb,cb;
    if(tam_a!=tam_b)
        dif_tam=tam_a-tam_b;
    dif_tam/=2;
    fb=fa-dif_tam;
    cb=ca-dif_tam;
    if(a[fa][ca]>b[fb][cb]){
        return true;
    }
    else return false;
}
