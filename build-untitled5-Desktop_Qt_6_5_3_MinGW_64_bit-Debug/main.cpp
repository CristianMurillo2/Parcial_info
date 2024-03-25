#include<P1.h>

int main(){
    int n,***ptr;
    cout << "ingrese un numero: "<< endl;
    cin>> n;
    while(n%2==0){
        cout<<"ingrese un numero impar "<<endl;
        cin>>n;
    }
    ptr=new int**[4];
    for(int i=0;i<4;i++){
        ptr[i]=ptr_new_p2(n);
    }
    for(int i=0;i<4;i++){
        if(i==0){
            original_matriz(ptr[0],n);
        }
        else rotate_matriz(ptr[i-1],ptr[i],n);
        cout<< "matiz rotada" <<endl<<endl;
        print_matriz(ptr[i],n);
    }
    for(int i=0;i<4;i++){
        ptr_delete_p2(ptr[i],n);

    }
    delete[] ptr;
    return 0;

}
