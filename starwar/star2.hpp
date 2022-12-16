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
        void deleteItem(T);
        bool empty(void);
        bool searchItem(T);
        void insertAfter(T dato, T datoRef);
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

void ListaDoble::deleteItem(T datoB){
    if(!pInicio){ // Lista vacía.
        cout << "Actualmente no hay películas." << endl;
    }
    else{ // Si la lista no está vacía, entonces:
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).titulo.compare(datoB.titulo)!=0) // Saltar.
            saltarin = saltarin->sig; // Luego de saltar hay varias posibilidades:
        if(!saltarin) // a) saltarín se salió (el dato no está en la lista).
            cout << "La película no está en la lista" << endl;
        else{ // Si saltarín no se salió (está sobre el dato a eliminar):
              // el nodo puede estar al principio, puede estar al final,
              // puede estar entre dos nodos, puede ser el único nodo.
            if(!saltarin->ant && saltarin->sig){ // Al principio (y hay más nodos).
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
            cout << "Película eliminada exitosamente!" << endl;
        }
    }
}

bool ListaDoble::empty(void){
    return pInicio == NULL;
}

bool ListaDoble::searchItem(T datoB){
    if(!pInicio){ // Lista vacía.
        cout << "Actualmente no hay películas." << endl;
        return false;
    }
    else{ // Si la lista no está vacía, entonces:
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).titulo.compare(datoB.titulo)!=0) // Saltar.
            saltarin = saltarin->sig; // Luego de saltar hay varias posibilidades:
        if(!saltarin) // a) saltarín se salió (el dato no está en la lista).
            return false;
        else
            return true;
    }
}

void ListaDoble::insertAfter(T dato, T datoRef){
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;

    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin;
        saltarin = pInicio;
        while(saltarin->sig != NULL && (saltarin->dato).titulo.compare(datoRef.titulo) != 0){
            saltarin = saltarin->sig;
        }
        nuevo->sig = saltarin->sig;
        nuevo->ant = saltarin;
        if(saltarin->sig != NULL)
            saltarin->sig->ant = nuevo;
        saltarin->sig = nuevo;

    }
}
