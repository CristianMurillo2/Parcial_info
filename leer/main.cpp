#include <iostream>

using namespace std;

int main() {
    char* cadena = nullptr;
    cout << "Ingrese una cadena de caracteres que represente un numero entero: ";
    char caracter;
    int longitud = 0;
    int capacidad = 10;
    cadena = new char[capacidad];
    while (cin.get(caracter) && caracter != '\n') {
        if (longitud == capacidad) {
            capacidad *= 2;
            char* temp = new char[capacidad];
            for (int i = 0; i < longitud; ++i) {
                temp[i] = cadena[i];
            }
            delete[] cadena;
            cadena = temp;
        }
        cadena[longitud++] = caracter;
    }
    int* arregloNumerico = new int[longitud];
    for (int i = 0; i < longitud; ++i) {
        if (cadena[i] >= '0' && cadena[i] <= '9') {
            arregloNumerico[i] = cadena[i] - '0';
        } else {
            cout << "Error: La cadena contiene caracteres no numericos." <<endl;
            delete[] cadena;
            delete[] arregloNumerico;
            return 0;
        }
    }
    cout << "El arreglo numerico es: ";
    for (int i = 0; i < longitud; ++i) {
        cout << arregloNumerico[i] << " ";
    }
    cout << endl;
    delete[] cadena;
    delete[] arregloNumerico;
    return 0;
}


