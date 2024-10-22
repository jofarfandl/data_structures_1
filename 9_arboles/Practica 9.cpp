//Arbol
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

struct nodo{
    int key;
    struct nodo *left, *right;
};

struct nodo* newNodo(int item){
    struct nodo* temp= (struct nodo*)malloc(sizeof(struct nodo));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void Enorder(struct nodo* root){
    if (root != NULL) {
        Enorder(root->left);
        cout << root->key<<" ";
        Enorder(root->right);
    }
}

struct nodo* insertar(struct nodo* nodo, int key){
    if (nodo == NULL)
        return newNodo(key);
    if (key < nodo->key)
        nodo->left = insertar(nodo->left, key);
    else
        nodo->right = insertar(nodo->right, key);
    return nodo;
}

struct nodo* minValueNode(struct nodo* root){
    struct nodo* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct nodo* eliminarNodo(struct nodo* root, int key){
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = eliminarNodo(root->left, key);
    else if (key > root->key)
        root->right = eliminarNodo(root->right, key);
    else {
        if (root->left == NULL) {
            struct nodo* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct nodo* temp = root->left;
            free(root);
            return temp;
        }

        struct nodo* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = eliminarNodo(root->right, temp->key);
    }
    return root;
}

bool buscar(struct nodo* root, int key){
    if (root == NULL)
        return false;
    if (root->key == key)
        return true;
    bool res1 = buscar(root->left, key);
    if(res1) return true;
    bool res2 = buscar(root->right, key);
    return res2;
}

bool vacia(struct nodo* root){
    if (root == NULL){
        return true;
    }
    else{
        return false;
    }
}

void anular(nodo* root){
    if (root == NULL)return;

    anular(root->left);
    anular(root->right);
    //cout << "\n Eliminando: " <<root->key;
    delete root;
}

void imprimir(nodo* root, int n){
     if(root==NULL)
          return;
     imprimir(root->right, n+1);
     cout<< root->key <<" ";
    imprimir(root->left, n+1);
}

void preOrden(nodo* root){
     if(root!=NULL){
          cout << root->key <<" ";
          preOrden(root->left);
          preOrden(root->right);
     }
}

void postOrden(nodo* root){
     if(root!=NULL){
          postOrden(root->left);
          postOrden(root->right);
          cout <<root->key<< " ";
     }
}

void menu(){
     cout<<"Arboles"<<endl;
     cout<<"1.-Vacia"<<endl;
     cout<<"2.-Insertar"<<endl;
     cout<<"3.-Eliminar"<<endl;
     cout<<"4.-En orden"<<endl;
     cout<<"5.-PreOrden"<<endl;
     cout<<"6.-PostOrden"<<endl;
     cout<<"7.-Buscar"<<endl;
     cout<<"8.-Anular"<<endl;
     cout<<"0.-Salir"<<endl;
     cout<<"Ingrese la opcion que desee...";
}

int main(){
    system("color 0b");//Dar color a las letras
    struct nodo* root = NULL;
    int x;
    int op, op2;
    do{
          system("cls");
          menu();
          cin>> op;
          switch(op){
               case 1:
                    if (vacia(root) == true){
                         cout<<"El arbol esta vacio"<<endl;
                    }else{
                         cout<<"El arbol tiene datos"<<endl;
                    }system("pause>>cls");break;
               case 2:
                    cout << " Ingrese valor: ";  cin>> x;
                    root = insertar(root, x);
                    system("cls");
                    break;
               case 3:
                    cout<<" Valor a eliminar: "; cin>> x;
                    root = eliminarNodo(root,x);
                    cout << "\n\tSe elimino el dato correctamente";
                    system("pause>>cls");
                    break;
                    
               case 4:
                    Enorder(root);
                    system("pause>>cls");
                    break;
               case 5:
                    preOrden(root);
                    system("pause>>cls");
                    break;
                case 6:
                    postOrden(root);
                    system("pause>>cls");
                    break;
               case 7:
                    cout << " Ingrese valor : ";  
                    cin>> x;
                    if (buscar(root, x))
                        cout << "El dato existe";
                    else
                        cout << "El Dato NO existe";
                    system("pause>>cls");
                    break;
               case 8:{
                    anular(root);
                    root = NULL;
                    cout << "\n Arbol eliminado exitosamente ";
                    system("pause>>cls");
                    break;}
               case 0:
                    cout<<"Fin del Programa"<<endl;
                    exit(0);
          }
          cout<<"\n\n\n";
    }while(op!=0);
    return 0;
}
