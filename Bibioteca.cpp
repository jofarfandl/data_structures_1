/*NOMBRE:FARFAN DE LEON JOSE OSVALDO
  CODIGO:214796622
  SECCION "D13" Estructura de Datos.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>

using namespace std;

struct tipo_fecha{
    int mes, anio;
}f[5];

struct tipo_ciudad{
    char ciudad[20];
    char pais[20];
}c[5];

struct biblioteca{
   int indice;
   char nombre[30];
   char tipo[30];
   struct tipo_fecha fecha_bib;
   struct tipo_ciudad ciudad_bib;
}b[5];

int index=0;
void actualizar();
int buscar(int);
void mostrar(int);
void listar();
int cve;

int main(){
    int opc, i;
    do {
            system("cls");
            cout << "\n\nMenu de Opciones" << endl;
            cout << "1. Actualizar registro." << endl;
            cout << "2. Mostrar registro dependiendo el indice ingresado." << endl;
            cout << "3. Mostrar todos los registros" << endl;
            cout << "4. SALIR" << endl;
            cout << "\nIngrese una opcion: ";
            cin >> opc;
            switch (opc) {
                case 1:
                    actualizar();
                    break;
                case 2:
                    cout<<"ingrese el indice:"<<endl;
                    cin>>i;
                    mostrar(buscar(i));
                    break;
                case 3:
                    system("pause>nul");
                    break;
                case 4:
                    cout<<"Saliendo del programa"<<endl;
                    system("pause");
                    break;
            }
        } while (opc != 4);
    return 0;
}

void actualizar(){
	char n[10][30];
	cout<<"ingrese el indice:"<<endl;
    cin>>b[index].indice;
	cout<<"ingrese nombre:"<<endl;
    cin.getline(b[index].nombre,20);
    cout<<"ingrese tipo de pelicula:"<<endl;
    cin>>b[index].tipo;
    cout<<"ingrese fecha"<<endl;
    cin>>b[index].fecha_bib.mes;
    cout<<"ingrese ciudad:"<<endl;
    cin>>b[index].ciudad_bib.ciudad;
    index++;
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
	cout<<"Indice: "<<b[pos].indice<<endl;
	cout<<"Nombre: "<<b[pos].nombre<<endl;
	cout<<"Tipo: "<<b[pos].tipo<<endl;
    cout<<"Fecha de estreno: "<<b[pos].fecha_bib.mes<<endl;
	cout<<"Ciudad: "<<b[pos].ciudad_bib.ciudad<<endl;
}
