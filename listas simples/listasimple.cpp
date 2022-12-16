// ADMINISTRACIÓN DE UNA LISTA LINEAL SIMPLEMENTE ENLAZADA
#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

class ListaSimple{

    private:
        nodo *pInicio;
    
    public:
        ListaSimple();
        void insertaNodo(void);
        void insInicio(int);
        void mostrarListaIter(void);
};

ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}

void ListaSimple::insertaNodo(void)
{
    int dato;

    cout << "Digite un entero o Ctrl-d para terminar: ";
    while(cin >> dato){
        insInicio(dato);
        cout << "Digite un entero o Ctrl-d para terminar: ";
    }
}

void ListaSimple::insInicio(int dato)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    pInicio = nuevo;
}

void ListaSimple::mostrarListaIter(void)
{
    nodo *saltarin;

    cout << endl;
    saltarin = pInicio;
    while(saltarin != NULL){
        cout << saltarin->dato << endl;
        saltarin = saltarin->sig;
    }
}

int main(void)
{
    cout << endl;
    cout << "ADMINISTRACIÓN DE LISTA LINEAL SIMPLEMENTE ENLAZADA" << endl << endl;

    ListaSimple objListaSimple;

    cout << "Insertar datos en la lista:" << endl;
    objListaSimple.insertaNodo();

    objListaSimple.mostrarListaIter();

    cout << endl;
    return 0;
}