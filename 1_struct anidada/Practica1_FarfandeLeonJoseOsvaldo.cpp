/*NOMBRE:FARFAN DE LEON JOSE OSVALDO
  SECCION "D13" Estructura de Datos.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
using namespace std;
//------------------------------------------------------------------
struct tipo_fecha{
    int mes, anio;
}f[5];

struct tipo_ciudad{
    char ciudad[20];
    char pais[20];
}c[5];

struct biblioteca{//ESTRUCTURA PRINCIPAL
   int indice;
   char nombre[30];
   char tipo[30];
   struct tipo_fecha fecha_bib;
   struct tipo_ciudad ciudad_bib;
}b[5];

//------------------------------------------------------------------
int index=0;
void actualizar();
int buscar(int);
void mostrar(int);
void mostrar_t();
int cve;



void actualizar(){
	if(index<5){
        cout<<"\ningrese el indice:"<<endl;
        cin>>b[index].indice;
        cout<<"ingrese nombre de la pelicula:"<<endl;
        cin>>b[index].nombre;
        cout<<"ingrese tipo de pelicula:"<<endl;
        cin>>b[index].tipo;
        cout<<"ingrese mes de estreno"<<endl;
        cin>>b[index].fecha_bib.mes;
        cout<<"ingrese anio de estreno"<<endl;
        cin>>b[index].fecha_bib.anio;
        cout<<"ingrese la ciudad de produccion:"<<endl;
        cin>>b[index].ciudad_bib.ciudad;
        cout<<"ingrese el pais de produccion:"<<endl;
        cin>>b[index].ciudad_bib.pais;
        index++;
        cout<<"Datos Actualizados"<<endl;
        system("pause");
	}
	else{
        cout<<"Registro lleno"<<endl;
        Sleep(1000);
	}
}

int buscar(int i){
	int x=0,ban=0,posicion=0;
	while(x<5 && ban==0){
		if(i==b[x].indice){
		   posicion=x;
		   ban=1;
		}
		x++;
	}
	return posicion;
}


void mostrar(int pos){
	cout<<"\nIndice: "<<b[pos].indice<<endl;
	cout<<"Nombre: "<<b[pos].nombre<<endl;
	cout<<"Tipo: "<<b[pos].tipo<<endl;
    cout<<"mes de estreno en numero: "<<b[pos].fecha_bib.mes<<endl;
    cout<<"anio de estreno: "<<b[pos].fecha_bib.anio<<endl;
	cout<<"Ciudad: "<<b[pos].ciudad_bib.ciudad<<endl;
    cout<<"Ciudad: "<<b[pos].ciudad_bib.pais<<endl;

}

void mostrar_t(){
    int i=0, posicion=0;
    if(index>0){
         for(int i=0 ; i<index ; i=i+1 ){
            posicion = i;
            mostrar(i);
         }
    }
    else{
        cout<<"Registro vacio"<<endl;
        system("pause");
    }
}
