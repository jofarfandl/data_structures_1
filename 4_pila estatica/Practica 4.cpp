//Pila estatica
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <stdio.h>
#define TAM 500
using namespace std;

typedef int type_dato;

typedef struct{
    type_dato datos[TAM];
    int tope;
}type_pila;

void inicializa(type_pila *T){
    T->tope = -1;
}

int vacia(type_pila *T){
    return T->tope == -1;
}

int llena(type_pila *T){
    return T->tope == TAM-1;
}

void push(type_pila *T){
    int d;
    if(llena(T)){
        cout<<"Desbordamiento de datos"<<endl;
    }else{
        cout<<"Ingrese el dato: ";
        cin>>d;
        T->tope++;
        T->datos[T->tope]=d;
    }
}

int pop(type_pila *T){
    if(vacia(T)){
        cout<<"Error... Insuficiencia de datos"<<endl;
        return 0;
    }else{
        cout<<"Se eliminara el dato["<<T->datos[T->tope]<<"] del tope ["<<T->tope<<"] correctamente"<<endl;
        T->tope--;
    }
}

int tope(type_pila *T){
    if(vacia(T)){
        cout << "!Error¡... No hay elementos." << endl;
        return-1;
    }else{
         cout<<"El tope es: "<<T->datos[T->tope]<<endl;
         return 0;
    }
}

void mostrar_pila(type_pila *T){
    for(int i=T->tope ; i>=0 ; i--){
        printf("\t\t%c ",186,205);
        cout<<T->datos[i]; printf(" %c\n",186);
        printf("\t\t%c%c%c%c%c\n",204,205,205,205,185);
    }
}

int menu(){
    system("color 0b");//Dar color a las letras
    int opc;
    cout<<"Menu"<<endl;
    cout<<"1.-Vacia"<<endl;
    cout<<"2.-Llena"<<endl;
    cout<<"3.-Inserta"<<endl;
    cout<<"4.-Elimina"<<endl;
    cout<<"5.-Tope"<<endl;
    cout<<"6.-Mostrar pila"<<endl;
    cout<<"0.-SALIR"<<endl;
    cout<<"Ingrese una opcion valida: ";
    cin>>opc;
    return opc;
}

int main(){
    int opc, band=1;
    type_pila _pila;
    type_pila *_pila2;
    _pila2= &_pila;
    inicializa(_pila2);
    do{
        system("cls");
        mostrar_pila(_pila2);
        switch(menu()){
            case 1:vacia(_pila2);cout<<vacia(_pila2)<<endl;system("pause");break;
            case 2:llena(_pila2);cout<<llena(_pila2)<<endl;system("pause");break;
            case 3:push(_pila2);cout<<"Dato agregado exitosamente"<<endl; break;
            case 4:pop(_pila2);system("pause");break;
            case 5:tope(_pila2);system("pause");break;
            case 6:mostrar_pila(_pila2);system("pause");break;
            case 0:system("cls");cout<<"FIN DEL PROGRAMA"<<endl;band=0;break;
            default:
                cout<<"ERROR... Dato invalido"<<endl;
                Sleep(2000);
        }

    }while(band != 0);

}
