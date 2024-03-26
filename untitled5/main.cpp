#include<P1.h>

int main(){
    int n,m,***ptr;

    cout << "ingrese la cantidad de matrices: "<< endl;
    cin>> m;
    for(int i=0;i<m;i++){
        cout << "ingrese las dimensiones de la matriz: "<< endl;
        cin>> n;
        while(n%2==0){
            cout<<"ingrese un numero impar "<<endl;
            cin>>n;
        }
        ptr=new int**[4];
        for(int i=0;i<4;i++){
            ptr[i]=ptr_new_p2(n);
    }
        original_matriz(ptr[i],n);
        print_matriz(ptr[i],n);
        for(int i=0;i<4;i++){
            ptr_delete_p2(ptr[i],n);
    }
    }
    delete[] ptr;
    return 0;

}
