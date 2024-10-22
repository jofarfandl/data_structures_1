//Cola Dinamica
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

int vacia(Nodo *&frente){
    if(frente == NULL){
        return 1;
    }else{
        return 0;
    }
}

void encolar(int num, Nodo *&frente, Nodo *&final){
    int aux;
    Nodo *nuevo_nodo= new Nodo();
    nuevo_nodo->dato = num;
    nuevo_nodo->siguiente = NULL;
    if(final != NULL){
        final->siguiente = nuevo_nodo;
    }
    final = nuevo_nodo;
    if(frente == NULL){
        frente = nuevo_nodo;
    }
}

void imprimir(Nodo *&frente){
    Nodo *temp;
    temp=frente;
    while(temp != NULL){
        cout<<temp->dato<<" ";
        temp = temp->siguiente;
    }
    cout<<""<<endl;
};

void desencolar(Nodo *&frente, Nodo *&final){
    Nodo *aux=frente;
    if(vacia(frente)){
        cout<<"Insuficiencia de datos"<<endl;
        system("pause");
        return;
    }
    aux = frente;
    frente = frente->siguiente;
    if(frente == NULL){
        final == NULL;
    }
    delete aux;
}

int main(){
    system("color 0b");//Dar color a las letras
    int opc, num;
    Nodo *frente=NULL;
    Nodo *final=NULL;
    do{
        system("cls");
        imprimir(frente);
        cout<<""<<endl;
        cout << "Menu:" << endl;
        cout << "1.- Vacia" << endl;
        cout << "2.-Encolar" << endl;
        cout << "3.-Desencolar" << endl;
        cout << "4.-Frente" << endl;
        cout << "5.-Imprimir" << endl;
        cout << "0.-SALIR"<<endl;
        cout<<"Ingrese una opcion valida: ";
        cin >> opc;
        switch(opc){
        case 1:
            cout<<vacia(frente)<<endl;system("pause");
            break;
        case 2:
            cout<<"Ingrese el elemento a agregar: ";
            cin>>num;
            encolar(num, frente, final);
            break;
        case 3:
            desencolar(frente, final);
            break;
        case 4:
            if(frente != NULL){
                cout<<frente->dato<<endl;system("pause");
            }else{
                cout<<"Insuficiencia de datos"<<endl;
                system("pause");
            }
            break;
        case 5:
            imprimir(frente);system("pause");
            break;
        case 0:
            cout<<"Fin del programa"<<endl;
            break;
        }
    }while(opc!=0);

    system("cls");
    return 0;
}
