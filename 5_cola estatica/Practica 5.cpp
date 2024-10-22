//Cola estatica
#include <iostream>
#include <cstdlib>
#include <windows.h>
#define TAM 10
using namespace std;

typedef int type_dato;

typedef struct{
    type_dato datos[TAM];
    int frente, final;
}type_cola;

void inicializa(type_cola *C){
    C->frente = 0;
    C->final = TAM-1;
}

int vacia(type_cola *C){
    if((C->frente==C->final+1)||(C->frente == 0 && C->final==TAM-1)){
        return 1;
    }else{
        return 0;
    }
}

int llena(type_cola *C){
    if( (C->frente==C->final+2)||(C->frente==0 && C->final==TAM-2)||(C->frente==1 && C->final==TAM) ){
        return 1;
    }else{
        return 0;
    }
}
//----------------------------------------------------------
void enqueue(type_cola *C){
    int elem;
    if(llena(C)){
        cout<<"Error... Desbordamiento de datos"<<endl;
    }else{
        cout<<"Ingrese el nuevo dato: ";
        cin>>elem;
        C->final++;
        if(C->final==TAM){
            C->final=0;
        }
        C->datos[C->final]=elem;
        cout<<"Dato agregado exitosamente"<<endl;
    }
}

void dequeue(type_cola *C){
    int aux;
    if(vacia(C)){
        cout<<"Error Cola vacia"<<endl;
    }else{
        aux=C->datos[C->frente];
        C->frente=(C->frente+1)%TAM;
        cout<<"Elemento eliminado: "<<aux<<endl;
    }
}

int frente(type_cola *C){
    if(vacia(C)){
        cout<<"ERROR... No hay elementos."<<endl;

        return -1;
    }else{
        cout<<"El frente es: "<<C->datos[C->frente]<<endl;
        return 0;
    }
}

void mostrar_cola(type_cola *C){
    if(vacia(C)){
        cout<<"Error...No hay elementos."<<endl;
    }else{
        for(int i=C->frente ; i<=C->final ;i++){
            cout<<" "<<C->datos[i];
        }
    }
}

int menu(){
    int opc;
    system("color 0b");//Dar color a las letras
    cout<<"\n\nMenu"<<endl;
    cout<<"1.-Vacia"<<endl;
    cout<<"2.-Llena"<<endl;
    cout<<"3.-Encolar"<<endl;
    cout<<"4.-Desencolar"<<endl;
    cout<<"5.-Frente"<<endl;
    cout<<"6.-Imprimir"<<endl;
    cout<<"0.-SALIR"<<endl;
    cout<<"Ingrese una opcion valida: ";
    cin>>opc;
    return opc;
}

int main(){
    int band=0, x=0;
    type_cola _cola;
    type_cola *_cola2;
    _cola2= &_cola;
    inicializa(_cola2);
    do{
        system("cls");
        //if(x >= )mostrar_cola(_cola2);
        switch(menu()){
            case 1:vacia(_cola2);cout<<vacia(_cola2)<<endl;system("pause");break;
            case 2:llena(_cola2);cout<<llena(_cola2)<<endl;system("pause");break;
            case 3:enqueue(_cola2);system("pause");x++;break;
            case 4:dequeue(_cola2);system("pause");x--;break;
            case 5:frente(_cola2);system("pause");break;
            case 6:mostrar_cola(_cola2);cout<<"\n";system("pause");break;
            case 0:system("cls");cout<<"FIN DEL PROGRAMA"<<endl;band=1;break;
            default:
                cout<<"ERROR... Dato invalido"<<endl;
                Sleep(2000);
        }
    }while(band!=1);
}
