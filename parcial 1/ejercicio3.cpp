/*Elabore un programa que contenga, dentro de su clase, dos funciones miembro y
 un puntero a lista simple. La primera función lee edades de personas desde teclado y
 las introduce en la lista, en un nuevo nodo cada una. La segunda función busca la mayor
de las edades y la imprime en pantalla.*/
#include <iostream>
using namespace std;

struct nodo
{
    int dato, edad;
    nodo *sig;
};

class ListaSimple
{
private:
    nodo *pInicio;

public:
    ListaSimple();
    void insertaNodo(void);
    void insInicio(int);
    void mostrarlistaIter(void);
    int mayorEdad();
};
int main(void)
{
    cout << endl;

    ListaSimple objListaSimple;
    cout << "Incertar datos en la lista: " << endl;
    objListaSimple.insertaNodo();
    objListaSimple.mostrarlistaIter();
   // objListasSimple.mayorEdad();

    cout << endl;
    return 0;
}
ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}

void ListaSimple::insertaNodo(void)
{
    int dato;

    cout << "Digite la edad o Ctrl-z para terminar: ";
    while (cin >> dato)
    {
        insInicio(dato);
    cout << "Digite la edad o Ctrl-z para terminar: ";
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

void ListaSimple::mostrarlistaIter(void)
{
    nodo *saltarin;
    saltarin = pInicio;
    while (saltarin != NULL)
    {
        cout << saltarin->dato<<endl;
        saltarin = saltarin->sig;
    }
}
int ListaSimple::mayorEdad(){
    int edadMayor = 0;
    nodo *explorador = pInicio;

    while(explorador != NULL){
        if(explorador->edad > edadMayor){
            edadMayor = explorador->edad;
        }
        explorador = explorador->sig;
    }

    return edadMayor;
}


