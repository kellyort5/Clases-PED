// ADMINISTRACIÓN DE UNA LISTA CIRCULAR SIMPLEMENTE ENLAZADA
#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

class ListaCircSimple{

    private:
        nodo *pInicio;
    
    public:
        ListaCircSimple();
        ~ListaCircSimple();
        void insertaNodo(void);
        void insInicio(int);
        void insFinal(int);
        void insOrdenAscendente(int);
        void mostrarListaCircIter(void);
        void mostrarListaRec(void);
        void mostrarListaRecAux(nodo *);
        void insDespuesElto(int, int);
        void eliminarListaCircRec(nodo *);
};

ListaCircSimple::ListaCircSimple(void)
{
    pInicio = NULL;
}

ListaCircSimple::~ListaCircSimple()
{
    cout << "Destructor ejecutándose" << endl;
    if(pInicio){
        eliminarListaCircRec(pInicio);
        pInicio = NULL;
    }
}

void ListaCircSimple::eliminarListaCircRec(nodo *p){
    if(p->sig != pInicio)
        eliminarListaCircRec(p->sig);
    delete p;
}

void ListaCircSimple::insertaNodo(void)
{
    int dato;

    cout << "Digite un entero o Ctrl-d para terminar: ";
    while(cin >> dato){
        //insInicio(dato);
        //insFinal(dato);
        insOrdenAscendente(dato);
        //cout << "Digite el dato despuès del cual insertar: ";
        //cin >> datoRef;
        //insDespuesElto(dato, datoRef);
        cout << "Digite un entero o Ctrl-d para terminar: ";
    }
    cout << endl;
}

void ListaCircSimple::insInicio(int dato)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else{
        nuevo->sig = pInicio;
        nodo *saltarin = pInicio;
        while(saltarin->sig != pInicio){
            saltarin = saltarin->sig;
        }
        saltarin->sig = nuevo;
        pInicio = nuevo;
    }
}

void ListaCircSimple::insFinal(int dato)
{
    nodo *nuevo, *saltarin;

    nuevo = new nodo;
    nuevo->dato = dato;

    if(!pInicio){ // Si la lista está vacía.
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else{ // Si la lista ya contiene nodos.
        nuevo->sig = pInicio;
        saltarin = pInicio;
        while(saltarin->sig != pInicio)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
    }
}

void ListaCircSimple::insOrdenAscendente(int dato)
{
    nodo *nuevo, *saltarin;

    nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else{
        if(dato < pInicio->dato){
            nuevo->sig = pInicio;
            saltarin = pInicio;
            while(saltarin->sig != pInicio)
                saltarin = saltarin->sig;
            saltarin->sig = nuevo;
            pInicio = nuevo;
        }
        else{
            saltarin = pInicio;
            while(saltarin->sig != pInicio && saltarin->sig->dato < dato)
                saltarin = saltarin->sig;
            nuevo->sig = saltarin->sig;
            saltarin->sig = nuevo;
        }
    }
}

void ListaCircSimple::mostrarListaCircIter(void)
{
    nodo *saltarin;

    cout << endl;
    if(pInicio){
        saltarin = pInicio;
        do{
            cout << saltarin->dato << endl;
            saltarin = saltarin->sig;
        }while(saltarin != pInicio);
    }
}

void ListaCircSimple::mostrarListaRec(void)
{
    mostrarListaRecAux(pInicio);
}

void ListaCircSimple::mostrarListaRecAux(nodo *saltarin)
{
    if(saltarin){
        mostrarListaRecAux(saltarin->sig);
        cout << saltarin->dato << endl;
    }
}

void ListaCircSimple::insDespuesElto(int dato, int datoRef)
{
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;

    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = NULL;
    }
    else{
        nodo *saltarin;
        saltarin = pInicio;
        while(saltarin->sig != NULL && saltarin->dato != datoRef){
            saltarin = saltarin->sig;
        }
        nuevo->sig = saltarin->sig;
        saltarin->sig = nuevo;
    }
}

int main(void)
{
    cout << endl;
    cout << "ADMINISTRACIÓN DE LISTA CIRCULAR SIMPLEMENTE ENLAZADA" << endl << endl;

    ListaCircSimple objListaCircSimple;

    cout << "Insertar datos en la lista:" << endl;
    objListaCircSimple.insertaNodo();

    objListaCircSimple.mostrarListaCircIter();

    cout << endl;
    return 0;
}