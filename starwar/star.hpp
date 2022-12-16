#include <iostream>
#include <string>
using namespace std;

//Definicion de nodo Pelicula y sus 2 funciones relacionadas
//Dichas funciones sirven para solicitar y mostrar peliculas

struct Pelicula{
    string titulo;
    int anio;
};

Pelicula solicitarPelicula(void){
    Pelicula p;
    cout << "Titulo: ";
    getline(cin, p.titulo);
    cout << "Anio de lanzamiento: ";
    cin >> p.anio; cin.ignore();
    return p;
}

void mostrarPelicula(Pelicula p){
    cout << "Titulo: " << p.titulo;
    cout << " (" << p.anio << ")." << endl;
}

//Uso de typedef para generalizar la lista doble con una plantilla

typedef Pelicula T;
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
        ~ListaDoble();
        void insertFront(T);
        void insertBack(T);
        void traversalForwardDirection(void);
        void traversalReverseDirection(void);
};

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertFront(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if(pInicio != NULL)
        pInicio->ant = nuevo;
    pInicio = nuevo;
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
        mostrarPelicula(saltarin->dato);//cout << saltarin->dato << endl;
        saltarin = saltarin->sig;
    }
}

void ListaDoble::traversalReverseDirection(void){
    if(!pInicio)
        return;
    nodo *p = pInicio;
    nodo *q = NULL;
    while(p){
        q = p;
        p = p->sig;
    }
    while(q){
        mostrarPelicula(q->dato);//cout << q->dato << endl;
        q = q->ant;
    }
}
