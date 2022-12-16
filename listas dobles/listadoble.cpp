#include <iostream>
using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
    nodo *ant;
};

class listadoble
{
private:
    nodo *pInicio;

public:
    listadoble();
    ~listadoble();
    void insertaNodo(void);
    void insInicio(int);
    void insfinal(int);    
    void mostrarlistadirecta(void);
    void mostrarlistaDI(void);
};

listadoble::listadoble(void)
{
    pInicio = NULL;
}

listadoble::~listadoble(void)
{
    cout << "Destructor ejecutandose" << endl;
    nodo *p;
    while (pInicio)
    {
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void listadoble::insertaNodo(void)
{
    int dato;

    cout << "Digite un entero o Ctrl-z para terminar: ";
    while (cin >> dato)
    {
        insfinal(dato);
        cout << "Digite un entero o Ctrl-z para terminar: ";
    }
}

void listadoble::insInicio(int dato)
{

    nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if (pInicio)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

void listadoble::insfinal(int dato){
    nodo *nuevo, *saltarin;
    nuevo = new nodo;
    nuevo->dato=dato;

    if(!pInicio){
        pInicio=nuevo;
        pInicio->sig=pInicio->ant=NULL;
    }
    else{
        saltarin = pInicio;
        while(saltarin->sig != NULL)
        saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL; 
    }


}

void listadoble::mostrarlistadirecta(void)
{
    nodo *saltarin;
    saltarin = pInicio;
    while (saltarin != NULL)
    {
        cout << saltarin->dato << endl;
        saltarin = saltarin->sig;
    }
}

void listadoble::mostrarlistaDI(void)
{
    nodo *p, *q;

    if (pInicio)
    {
        p = pInicio;
        q = NULL;
        while (p)
        {
            cout << p->dato << endl;
            q = p;
            p = p->sig;
        }
        q = q->ant;
        while (q)
        {
            cout << q->dato << endl;
            q = q->ant;
        }
    }
}

int main(void)
{
    cout << endl;
    cout << "ADMINISTRACION DE LISTA LINEAL DOBLEMENTE ENLAZADA" << endl;

    listadoble objListadoble;
    cout << "Incertar datos en la lista: " << endl<<endl;
    objListadoble.insertaNodo();
    cout << "Mostrando solo en sentido directo: " << endl;
    objListadoble.mostrarlistadirecta();
    cout << endl << "Mostrando en sentido directo e inverso: " << endl;
    objListadoble.mostrarlistaDI();
    cout << endl;
    return 0;
}