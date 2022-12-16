#include <iostream>
#include <string>
using namespace std;

struct Estrato
{
    string nombre;
    float x;
};

Estrato solicitarEstrato(void)
{
    Estrato p;
    cout << "Ingrese el nombre del estrato: " << endl;
    getline(cin, p.nombre);
    cout << "Ingrese el grosor: " << endl;
    cin >> p.x;
    cin.ignore();
    return p;
}

typedef Estrato T;
const T noValido = {" ", -1};

struct nodo
{
    T dato;
    nodo *sig;
};

class Pila
{
private:
    nodo *pTope;

public:
    Pila();
    ~Pila();
    void push(T);
    bool empty(void);
    float sumEstratos(nodo *nodo);
};

Pila::Pila(void)
{
    pTope = NULL;
}

Pila::~Pila()
{
    nodo *p;
    while (pTope)
    {
        p = pTope;
        pTope = pTope->sig;
        delete p;
    }
}

void Pila::push(T dato)
{
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pTope;
    pTope = nuevo;
}

bool Pila::empty(void)
{
    return (pTope == NULL);
}

float Pila::sumEstratos(nodo *nodo)
{
    float suma = 0;
    if (nodo == NULL)
    {
        cout << "\nLa pila esta vacia" << endl;
    }
    else
    {
        while (nodo != NULL)
        {
            suma = suma+nodo->dato;
            nodo = nodo->sig;
        }
    }
    return suma;
}
