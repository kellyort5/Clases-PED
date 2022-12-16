// ADMINISTRACIÓN DE UNA LISTA LINEAL DOBLEMANTE ENLAZADA
#include <iostream>
#include <unistd.h> // En Unix - Linux

using namespace std;

struct nodo{
    int dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{

    private:
        nodo *pInicio;
    
    public:
        ListaDoble();
        ~ListaDoble();
        void insertaNodo(void);
        void insInicio(int);
        void insFinal(int);
        void mostrarListaDirectoIter(void);
        void mostrarListaDIIter(void);
        void mostrarListaRec(void);
        void mostrarListaRecAux(nodo *);
        void insDespuesElto(int, int);
        void insAntesElto(int, int);
        void eliminarNodo(int);
};

ListaDoble::ListaDoble(void)
{
    pInicio = NULL;
}

ListaDoble::~ListaDoble()
{
    cout << "Destructor ejecutándose" << endl;
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertaNodo(void)
{
    int dato, datoRef;

    cout << "Digite un entero o Ctrl-d para terminar: ";
    while(cin >> dato){
        //insInicio(dato);
        insFinal(dato);
        //cout << "Digite el dato después del cual insertar: ";
        //cout << "Digite el dato antes del cual insertar: ";
        //cin >> datoRef;
        //insDespuesElto(dato, datoRef);
        //insAntesElto(dato, datoRef);
        cout << "Digite un entero o Ctrl-d para terminar: ";
    }
    cin.clear();
    cout << endl;
}

void ListaDoble::insInicio(int dato)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if(pInicio)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

void ListaDoble::insFinal(int dato)
{
    nodo *nuevo, *saltarin;

    nuevo = new nodo;
    nuevo->dato = dato;

    if(!pInicio){ // Si la cola está vacía.
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{ // Si la cola ya contiene nodos.
        saltarin = pInicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void ListaDoble::mostrarListaDirectoIter(void)
{
    nodo *saltarin;

    cout << endl;
    saltarin = pInicio;
    while(saltarin != NULL){
        cout << saltarin->dato << endl;
        saltarin = saltarin->sig;
    }
}

void ListaDoble::mostrarListaDIIter(void)
{
    nodo *p, *q;
    unsigned int microsecond = 1000000; // En Unix - Linux


    cout << endl;
    if(pInicio){
        p = pInicio;
        q = NULL;
        while(p){
            cout << p->dato << endl;
            q = p;
            p = p->sig;
        }
        q = q->ant;
        while(q){
            usleep(2 * microsecond);  // En Unix - Linux
            cout << q->dato << endl;
            q = q->ant;
        }
    }
}

void ListaDoble::mostrarListaRec(void)
{
    mostrarListaRecAux(pInicio);
}

void ListaDoble::mostrarListaRecAux(nodo *saltarin)
{
    if(saltarin){
        mostrarListaRecAux(saltarin->sig);
        cout << saltarin->dato << endl;
    }
}

void ListaDoble::insDespuesElto(int dato, int datoRef)
{
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
        while(saltarin->sig != NULL && saltarin->dato != datoRef){
            saltarin = saltarin->sig;
        }
        nuevo->sig = saltarin->sig;
        nuevo->ant = saltarin;
        if(saltarin->sig != NULL)
            saltarin->sig->ant = nuevo;
        saltarin->sig = nuevo;

    }
}

void ListaDoble::insAntesElto(int dato, int datoRef)
{
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;

    if(!pInicio){
        cout << "Caso de inserción en losta vacía" << endl;
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin;
        saltarin = pInicio;
        while(saltarin->sig != NULL && saltarin->dato != datoRef){
            saltarin = saltarin->sig;
        }
        if(saltarin->dato != datoRef){ // Si datoRef no está en la lista.
            cout << "Caso de inserción al final" << endl;
            saltarin->sig = nuevo;
            nuevo->ant = saltarin;
            nuevo->sig = NULL;
        }
        else
            if(!saltarin->ant){ // Si datoRef está al principio.
                cout << "Caso de inserción al inicio" << endl;
                nuevo->sig = pInicio;
                pInicio->ant = nuevo;
                pInicio = nuevo;
                pInicio->ant = NULL;
            }else
                if(saltarin && saltarin->ant){
                    cout << "Caso de inserción enmedio" << endl;
                    nuevo->sig = saltarin;
                    nuevo->ant = saltarin->ant;
                    saltarin->ant->sig = nuevo;
                    saltarin->ant = nuevo;
                }
    }
}

void ListaDoble::eliminarNodo(int datoB)
{
    if(!pInicio){ // Lista vacía.
        cout << "La lista está vacía" << endl;
    }
    else{ // Si la lista no está vacía, entonces:
        nodo *saltarin = pInicio;
        while(saltarin && saltarin->dato != datoB) // Saltar.
            saltarin = saltarin->sig; // Luego de saltar hay varias posibilidades:
        if(!saltarin) // a) saltarín se salió (el dato no está en la lista).
            cout << "El dato no está en la lista" << endl;
        else // Si saltarín no se salió (está sobre el dato a eliminar):
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
    }
}

int main(void)
{
    cout << endl;
    cout << "ADMINISTRACIÓN DE LISTA LINEAL DOBLEMANTE ENLAZADA" << endl << endl;

    ListaDoble objListaDoble;

    cout << "Insertar datos en la lista:" << endl;
    objListaDoble.insertaNodo();

    cout << "Mostrando solo en sentido directo:" << endl;
    objListaDoble.mostrarListaDirectoIter();

    cout << "Mostrando en sentido directo e inverso:" << endl;
    objListaDoble.mostrarListaDIIter();

    objListaDoble.eliminarNodo(50);

    cout << "Mostrando solo en sentido directo:" << endl;
    objListaDoble.mostrarListaDirectoIter();

    cout << "Mostrando en sentido directo e inverso:" << endl;
    objListaDoble.mostrarListaDIIter();

    //cin >> datoB;

    cout << endl;
    return 0;
}