//Torres de hanoi
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>

using namespace std;
int salir=0;

 void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

 void TextColor(int color){
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

struct Nodo{
  int datos;
  struct Nodo *siguiente;
};


void inicializa(struct Nodo *&pila);
int vacia(struct Nodo *&pila);
void push(int elemento, struct Nodo *&pila);
void pop(struct Nodo *&pila);
int top(struct Nodo *&pila);
void llena(struct Nodo *&pila, int numDiscos);
void imprime(struct Nodo *&pila, int clv);
void imprime2(struct Nodo *&pila, int clv);
void imprime3(struct Nodo *&pila, int clv);
void menu(struct Nodo *&pila1, struct Nodo *&pila2, struct Nodo *&pila3);
void ganador(struct Nodo *&pila1, struct Nodo *&pila2);

void inicializa (struct Nodo *&pila){
  pila = NULL;
}

int vacia(struct Nodo *&pila){
    if(pila == NULL){
        return true;
    }else{
        return false;
    }
}

void llena(struct Nodo *&pila, int numDiscos){
    for(int i = numDiscos; i >= 1; i--){
        push(i, pila);
    }
}

void push(int elemento, struct Nodo *&pila){
    struct Nodo *aux = new struct Nodo;
    aux->datos = elemento;
    aux->siguiente = pila;
    pila = aux;
}

void pop(struct Nodo *&pila){
    if(vacia(pila) == 1){
        system("CLS");
        TextColor(4);
        gotoxy(12,10);cout<<"**********************"<<endl;
        gotoxy(12,11);cout<<"*   Falta de datos   *"<<endl;
        gotoxy(12,12);cout<<"**********************"<<endl;
        TextColor(15);
        system("pause");
        system("cls");
    }else{
        struct Nodo *aux = new struct Nodo;
        aux = pila;
        pila = pila->siguiente;
        delete aux;
    }
}

int top(struct Nodo *&pila){
    if (vacia(pila) == 1){
        return -1;
    }else{
        return pila->datos;
    }
}

void menu(struct Nodo *&pila1, struct Nodo *&pila2, struct Nodo *&pila3){
    int VC = 0, clv=0;
    do{
        system("cls");
        int opcion = 0;
        TextColor(4);
        imprime(pila1, 4);
        TextColor(3);
        imprime2(pila2, 3);
        TextColor(6);
        imprime3(pila3, 6);
        TextColor(15);
        gotoxy(40,2);cout<<"1.- Mueve de pila A a B";
        gotoxy(40,3);cout<<"2.- Mueve de pila A a C";
        gotoxy(40,4);cout<<"3.- Mueve de pila B a A";
        gotoxy(40,5);cout<<"4.- Mueve de pila B a C";
        gotoxy(40,6);cout<<"5.- Mueve de pila C a A";
        gotoxy(40,7);cout<<"6.- Mueve de pila C a B";
        gotoxy(40,8);cout<<"0. SALIR";
        gotoxy(40,9);cout<<"OPCION: ";
        gotoxy(40,10);cin>>opcion;
        switch(opcion){
            case 1:
                if(top(pila2) == -1 || top(pila1) < top(pila2)){
                    push(top(pila1), pila2);
                    pop(pila1);
                }else if(top(pila1) > top(pila2)){
                    gotoxy(20,15); cout<<"Imposible"<<endl;
                    system("pause");
                }
            break;
            case 2:
                if(top(pila3) == -1 || top(pila1) < top(pila3)){
                    push(top(pila1), pila3);
                    pop(pila1);
                }else if(top(pila1) > top(pila3)){
                    gotoxy(20,15); cout<<"Imposible"<<endl;
                    system("pause");
                }
            break;
            case 3:
                if(top(pila1) == -1 || top(pila2) < top(pila1)){
                    push(top(pila2), pila1);
                    pop(pila2);
                }else if(top(pila2) > top(pila1)){
                    gotoxy(20,15); cout<<"Imposible"<<endl;
                    system("pause");
                }
            break;
            case 4:
                if(top(pila3) == -1 || top(pila2) < top(pila3)){
                    push(top(pila2), pila3);
                    pop(pila2);
                }else if(top(pila2) > top(pila3)){
                    gotoxy(20,15); cout<<"Imposible"<<endl;
                    system("pause");
                }
            break;
            case 5:
                if(top(pila1) == -1 || top(pila3) < top(pila1)){
                    push(top(pila3), pila1);
                    pop(pila3);
                }else if(top(pila3) > top(pila1)){
                    gotoxy(20,15); cout<<"Imposible"<<endl;
                    system("pause");
                }
            break;
            case 6:
                if(top(pila2) == -1 || top(pila3) < top(pila2)){
                    push(top(pila3), pila2);
                    pop(pila3);
                }else if(top(pila3) > top(pila2)){
                    gotoxy(20,15); cout<<"Imposible"<<endl;
                    system("pause");
                }
            break;
            case 0:{
                salir = 1;
                system("cls");
                cout<<"FIN DEL PROGRAMA"<<endl;
                break;
            }
            default:
                cout<<"Error... Intentelo de nuevo";
                menu(pila1, pila2, pila3);
            break;
        }
        ganador(pila1, pila2);
    }while(salir!=1);
}

void imprime(struct Nodo *&pila, int clv){
    int cont=2;
    TextColor(clv);
    struct Nodo *aux = new struct Nodo;
    aux = pila;
    while(aux != NULL){
        gotoxy(2,cont);cout<<aux->datos<<""<<endl;
        aux = aux->siguiente;
        cont++;
    }
    gotoxy(2,10);cout<<"A"<<endl;
}
void imprime2(struct Nodo *&pila, int clv){
    int cont=2;
    TextColor(clv);
    struct Nodo *aux = new struct Nodo;
    aux = pila;
    while(aux != NULL){
        gotoxy(10,cont);cout<<aux->datos<<""<<endl;
        aux = aux->siguiente;
        cont++;
    }
    gotoxy(10,10);cout<<"B"<<endl;
}
void imprime3(struct Nodo *&pila, int clv){
    int cont=2;
    TextColor(clv);
    struct Nodo *aux = new struct Nodo;
    aux = pila;
    while(aux != NULL){
        gotoxy(20,cont);cout<<aux->datos<<""<<endl;
        aux = aux->siguiente;
        cont++;
    }
    gotoxy(20,10);cout<<"C"<<endl;
}


void ganador(struct Nodo *&pila1, struct Nodo *&pila2){
    if(vacia(pila1) == 1 && vacia(pila2)==1){
        salir=1;
        system("cls");
        cout<<" --------------------------------------------- "<<endl;
        cout<<"|                                             |"<<endl;
        cout<<"| F E L I C I D A D E S  H A S  G A N A D O   |"<<endl;
        cout<<"|                                             |"<<endl;
        cout<<" --------------------------------------------- "<<endl;
        TextColor(15);
    }else{
        return;
    }
}

int main(){
    system("color 0b");//Dar color a las letras
    int num;
    struct Nodo *pila1;
    struct Nodo *pila2;
    struct Nodo *pila3;
    inicializa(pila1);
    inicializa(pila2);
    inicializa(pila3);
    cout<<"TORRES DE HANOI"<<endl;
    cout<<"Ingrese la cantidad de discos deseados: "<<endl;
    cin>>num;
    llena(pila1, num);
    system("cls");
    menu(pila1, pila2, pila3);
}

