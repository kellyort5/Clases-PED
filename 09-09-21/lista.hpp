#include <iostream>
#include <string>
using namespace std;

struct nodo{
    double monto;
    string descripcion;
    nodo *sig;
};

class ListaSimple{
    private:
        nodo *pInicio;
    public:
        ListaSimple();
        ListaSimple(double);
        ListaSimple(double, string);
        void insInicio(double);
        void insInicio(double, string);
        void mostrarListaIter(void);
        double calcularBalance(void);
};

ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}

ListaSimple::ListaSimple(double monto)
{
    pInicio = NULL;
    insInicio(monto);
}

ListaSimple::ListaSimple(double monto, string d)
{
    pInicio = NULL;
    insInicio(monto, d);
}

void ListaSimple::insInicio(double dato)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->monto = dato;
    nuevo->sig = pInicio;
    pInicio = nuevo;
}

void ListaSimple::insInicio(double dato, string d)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->monto = dato;
    nuevo->descripcion = d;
    nuevo->sig = pInicio;
    pInicio = nuevo;
}

void ListaSimple::mostrarListaIter(void)
{
    nodo *saltarin;

    cout << endl;
    saltarin = pInicio;
    while(saltarin != NULL){
        cout << "Descripcion: " << saltarin->descripcion << endl;
        cout << "Monto: " << saltarin->monto << " BT" << endl;
        saltarin = saltarin->sig;
    }
}

double ListaSimple::calcularBalance(void)
{
    nodo *saltarin;
    double balance = 0;

    cout << endl;
    saltarin = pInicio;
    while(saltarin != NULL){
        // balance = balance + algo
        balance += saltarin->monto;
        saltarin = saltarin->sig;
    }
    return balance;
}
