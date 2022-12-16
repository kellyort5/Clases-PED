#include <iostream>
#include <string>
using namespace std;

struct pedido{
    string desc;
    int i;
};

pedido solicitarpedido(void){
    pedido p;
    cout << "Ingrese el pedido: ";
    getline(cin, p.desc);
    cout <<"Cuantos pedidos desea: ";
    cin >> p.i; cin.ignore(); 
    return p;
}

void mostrarpedido(pedido p){
    cout << "pedido: " << p.desc;
    cout << " (" << p.i << ")." << endl;
}

typedef pedido T;
const T noValido = {"",0};

struct nodo{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        ListaDoble();
        void insertBack(T);
        void traversalForwardDirection(void);
        void deleteItem(T);
        bool empty(void);
};

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

void ListaDoble::insertBack(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin = pInicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void ListaDoble::traversalForwardDirection(void){
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        mostrarpedido(saltarin->dato);
        saltarin = saltarin->sig;
    }
}

void ListaDoble::deleteItem(T datoB){
    if(!pInicio){ 
        cout << "Actualmente no hay pedidos." << endl;
    }
    else{ 
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).desc.compare(datoB.desc)!=0) 
            saltarin = saltarin->sig; 
        if(!saltarin) 
            cout << "El pedido no está en la lista" << endl;
        else{ 
            if(!saltarin->ant && saltarin->sig){ 
                pInicio = pInicio->sig;
                pInicio->ant = NULL;
                delete saltarin;
            }
            else
                if(saltarin->ant && !saltarin->sig){
                    saltarin->ant->sig = NULL;
                    delete saltarin;
                }
                else
                    if(saltarin->ant && saltarin->sig){
                        saltarin->ant->sig = saltarin->sig;
                        saltarin->sig->ant = saltarin->ant;
                        delete saltarin;
                    }
                    else{
                        pInicio = NULL;
                        delete saltarin;
                    }
            cout << "Pedido eliminado exitosamente!" << endl;
        }
    }
}

bool ListaDoble::empty(void){
    return pInicio == NULL;
}
