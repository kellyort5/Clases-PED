/*hacer un programa para agregar numeros enteros a una pila, hasta que 
el usuario lo decida, despues mostrar todos los numeros
introducidos en la pila*/
#include <iostream>
//#include <stdlib.h>
using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};    

void agregar(nodo*&, int);
void sacar(nodo*&, int &);

int main(){
    nodo *pila = NULL;
    int dato;
    char res;
    do{
        cout <<"digite un numero: "<<endl;
        cin >>dato;
        agregar(pila, dato);

        cout<<"\nDesea agregar otro elemento a la pila(s/n): "<<endl;
        cin >>res;
    }while((res=='S')||(res=='s'));

    cout <<"\nSacando todos los elementos de Pila: "<<endl;
    while(pila!=NULL){
        sacar(pila, dato);
        if(pila != NULL){
            cout <<dato<<" - ";
        }
        else{
            cout <<dato<<" . ";
        }
    }

    return 0;
}

void agregar(nodo*&pila, int n){
    nodo *nuevo = new nodo();
    nuevo->dato = n;
    nuevo->sig = pila;
    pila = nuevo;

    cout <<"\tElemento "<<n<<" agregado a la pila" <<endl;
}

void sacar(nodo*&pila, int &n){
    nodo *aux = pila;
    n = aux->dato;
    pila = aux->sig;
    delete aux;
}
