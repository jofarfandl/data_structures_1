/*Farfan de Leon Jose Osvaldo
  Codigo: 214796622
  Materia: Estructura de datos "D13"
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include <windows.h>
#define TAM 5
#define FALSE 0
#define TRUE 1
using namespace std;

typedef int type_pos;
typedef int type_dato;
typedef int type_elem;
typedef struct{
    type_dato datos[TAM];
    int ultimo;
}type_list;
//-------------------------------------------------------------
void inicializa(type_list *L){
    L->ultimo = -1;
}
int vacia(type_list *L){
    return L->ultimo == -1;
}
int llena(type_list *L){
    return L->ultimo == TAM-1;
}
void inserta(type_dato d, type_pos pos, type_list *L){
    if(llena(L) || pos < 0 || pos > L->ultimo + 1){
            cout << "Error... Posicion incorrecta" << endl;
            system("pause");
    }
    else{
        for(int i = L->ultimo + 1 ; i > pos ; i --){
            L->datos[i]=L->datos[i-1];
        }
        L->datos[pos]=d;
        L->ultimo++;
        system("cls");
    }
}
void elimina(type_pos pos, type_list *L){
    if(vacia(L)||pos<0||pos>L->ultimo){
            cout << "!Error¡... No hay elemento que eliminar." << endl;
        return;
    }
    else{

        for(int i=pos ; i<L->ultimo ; i++){
            L->datos[i]=L->datos[i+1];
        }
        L->ultimo--;
    }
    system("cls");
}
int primero(type_list *L){
    if(vacia(L)){
        cout << "!Error¡... No hay elementos." << endl;
        system("pause");
        return-1;
    }
    else{
        cout<<"Primer elemento: "<<L->datos[0]<<endl;
        return 0;
    }
}
int ultimo(type_list *L){
        cout<<"Ultimo elemento: "<<L->datos[L->ultimo]<<endl;
        return 0;
}

int busqueda_lineal(type_elem elem, type_dato d, type_list *L){
    int i=0;
    while(i<=L->ultimo){
        if(elem == L->datos[i]){
            cout<<"La pocision del dato es: "<<i<<endl;
            system("pause");
            break;
        }
        i++;
    }
    return -1;
}

int busqueda_binaria(type_elem elem, type_dato d, type_list *L){
    int i=0;
    int j=L->ultimo;
    while(i<j){
        int medio;
        medio=(i+j)/2;
        if(L->datos[medio]==elem){
            cout<<"La pocision del dato es: "<<medio<<endl;
            system("pause");
            break;
        }
        if(elem < L->datos[medio]){
            j=medio-1;
        }else{
            i=medio+1;
        }

    }
    return -1;
}


int recupera(type_pos pos, type_list *L){
    if(vacia(L) || pos < 0 || pos > L->ultimo){
        cout << "!Error...Pocision aun sin ingresar en la lista." << endl;
        system("pause");
    }
    else{
        cout<<"Dato: "<< L->datos[pos]<<endl;
        return 0;
    }
}
int imprime(type_list *L){
    int i=0;
    cout<<"la lista es:"<<endl;
    while(i< L->ultimo+1){
        cout<<L->datos[i]<<" ";
        i++;
    }
    cout<<" "<<endl;
    system("pause");
}
void anula(type_list *L){
    L->ultimo = -1;
}

int burbuja(type_list *L){
    int aux, i , j;
    i=L->ultimo;
    while(i>0){
        j=0;
        while(j<i){
            if(L->datos[j] > L->datos[j+1]){
                aux=L->datos[j];
                L->datos[j]=L->datos[j+1];
                L->datos[j+1] = aux;
            }
            j++;
        }
        i--;
    }
}

int insercion(type_list *L){
    int aux, i=1, j;
    while(i<=L->ultimo){
        aux=L->datos[i];
        j=i;
        while(j>0 && aux < L->datos[j-1]){
            L->datos[j]=L->datos[j-1];
            j--;
        }
        if(i!= j){
            L->datos[j]=aux;
        }
        i++;
    }
}
//------------------------------------------------------------------------------
int quicksort(type_list *L, int extizq, int extder){
    int i, j, aux=1;
    if(extizq >= extder){
        return 0;
    }
    aux = L->datos[(extizq+extder)/2];
    L->datos[(extizq+extder)/2] = L->datos[extder];
    L->datos[extder] = aux;
    i = extizq;
    j = extder;
    while(i<j){
        while(i<j && (L->datos[i] <= L->datos[extder])){
            i++;
        }
        while(i<j && (L->datos[j] >= L->datos[extder])){
            j--;
        }
        if(i!=j){
            aux=L->datos[i];
            L->datos[i]=L->datos[j];
            L->datos[j]=aux;
        }
    }
    if(i!=extder){
        aux=L->datos[i];
        L->datos[i]=L->datos[extder];
        L->datos[extder]=aux;
    }
    quicksort(L, extizq, i-1);
    quicksort(L, i+1, extder);
}
//----------------------------------------------------------------------------------
int mezcla(type_list *L, int extizq, int extder){
    int medio, i , j, x;
    int temp[TAM];
    if(extizq >= extder){
        return 0;
    }
    medio = (extizq+extder)/2;
    mezcla(L, extizq, medio);
    mezcla(L, medio+1, extder);

    for (int k=extizq ; k<=extder ; k++){
        temp[k]=L->datos[k];
    }
    //temp[extizq..extder] = L->datos[extizq..extder];

    i=extizq, j=medio+1, x=extizq;
    while(i<=medio && j<=extder){
        while(i<=medio && temp[i] <= temp[j]){
            L->datos[x] = temp[i], i++, x++;
        }
        if(i<=medio){
            while(j<=extder && temp[j]<= temp[i]){
                L->datos[x]=temp[j], j++, x++;
            }
        }
    }
    while(i<=medio){
        L->datos[x]=temp[i],i++,x++;
    }
    while(j<=extder){
       L->datos[x]=temp[j],i++,x++;
    }
}

//---------------------------------------------------------------------------------
int menu(){
    int opc=0;
    cout<<"----Menu de opciones----"<<endl;
    cout<<"1.-Vacia"<<endl;
    cout<<"2.-Llena"<<endl;
    cout<<"3.-Inserta"<<endl;
    cout<<"4.-Elimina"<<endl;
    cout<<"5.-Primero"<<endl;
    cout<<"6.-Ultimo"<<endl;
    cout<<"7.-Buscar"<<endl;
    cout<<"8.-Recupera"<<endl;
    cout<<"9.-Ordena"<<endl;
    cout<<"10.-Imprime"<<endl;
    cout<<"11.-Anula"<<endl;
    cout<<"0. SALIR"<<endl;
    cout<<"Ingrese una opcion valida: ";
    cin>>opc;
    return opc;
}
//--------------------------------------------------------------------
int main(){
    int opc, opc2=0, posm=0, datm=0, band=1, elem=0;
    type_list lista;
    type_list *lista2;
    lista2= &lista;
    inicializa(lista2);
    do {
            system("cls");
            switch (menu()) {
                case 1:vacia(lista2);cout<<vacia(lista2)<<endl;system("pause");break;
                case 2:llena(lista2);cout<<llena(lista2)<<endl;system("pause");break;
                case 3: cout<<"Ingrese la posicion:"<<endl;
                        cin>> posm;
                        cout<<"Que dato: ";
                        cin>>datm;
                        inserta(datm,posm,lista2);
                    break;
                case 4: cout<<"Ingrese la posicion a eliminar:";
                        cin>> posm;
                        elimina(posm,lista2);
                    break;
                case 5:primero(lista2);system("pause");break;
                case 6:ultimo(lista2);system("pause");break;
                case 7: cout<<"1.-Busqueda lineal\n2.-Busqueda binaria\nIngrese un opcion valida: ";
                        cin >> opc2;
                        cout<<"Ingrese el elemento a buscar: "<<endl;
                        cin>>elem;
                        switch(opc2){
                            case 1:busqueda_lineal(elem, datm, lista2);break;
                            case 2:burbuja(lista2);busqueda_binaria(elem, datm, lista2);break;
                        }
                break;

                case 8:
                        cout<<"Ingrese la posicion:";
                        cin>> posm;
                        recupera(posm,lista2);system("pause");
                    break;
               case 9:
                        cout<<"1.-Metodo burbuja\n2.-Metodo de insercion\n3.-Quicksort\n4.-Mezcla\nIngrese una opcion valida: ";
                        cin >> opc2;
                        switch(opc2){
                            case 1:burbuja(lista2);break;
                            case 2:insercion(lista2);break;
                            case 3:quicksort(lista2,primero(lista2),ultimo(lista2));break;
                            case 4:mezcla(lista2,primero(lista2),ultimo(lista2));break;
                        }
                        cout<<"La lista se ordeno exitosamente "<<endl;
                    break;
                case 10:imprime(lista2);break;
                case 11:anula(lista2);break;
                case 0:system("cls");cout<<"Programa finalizado"<<endl;band=0;break;
                default:
                    cout<<"!Error¡... Dato invalido"<<endl;
                    Sleep(2000);
                }
        } while (band != 0);
    return 0;
}
