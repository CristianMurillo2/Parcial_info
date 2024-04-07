#include<P1.h>

int main(){
    int i=0,m=2;
    int*array=arreglo();
    int tam_min,f=array[0],c=array[1];
    bool bandera=false,mat,cond=false;
    int longitud=0;
    int ***ptr;
    int **matriz1,**matriz2;
    while (array[longitud]!='\0'){
        longitud++;
    }
    int *tam_mat=new int[longitud-2];
    int *tam_rot=new int[longitud-2];
    if(array[i]>array[i+1]){
        tam_min=array[i];
        if(tam_min%2==0){
            tam_min+=1;
        }
    }
    else{
        tam_min=array[i+1];
        if(tam_min%2==0){
            tam_min+=1;
        }
    }
    ptr=new int**[4];
    for(int i=0;i<4;i++){
        ptr[i]=ptr_new_p2(tam_min);
    original_matriz(matriz1,tam_min);
    original_matriz(matriz2,tam_min);
    while(m<longitud){
        int dim=0;
        int rot=0,cant_rot=0;
        int tam_min_aux=tam_min;
        switch (array[m]) {
        case 1:
            while(cond){
                mat=comparar(matriz1,matriz2,tam_min,tam_min,f,c);
                if(mat==false){
                    int tam_min_aux=tam_min+2;
                    original_matriz(matriz1,tam_min_aux);
                }
                else{
                    tam_mat[dim]=tam_min_aux;
                    tam_rot[rot]=cant_rot;
                    cond=true;
                    m++;
                }
            }
            break;
        case -1:
            break;
        }
    }
}
}

