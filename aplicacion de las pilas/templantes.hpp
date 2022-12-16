#include <iostream>
using namespace std;

struct Placa{
    char tipo;
    int numero;
};

typedef Placa T;
const T noValido = {'Z',000};

struct nodo{
    T dato;
    nodo *sig;
};

class Pila{
    private:
        nodo *pTope;
    public:
        Pila();
        ~Pila();
        void push(T);
        T pop(void);
        T top(void);
        bool empty(void);
};

Pila::Pila(void){
    pTope = NULL;
}

Pila::~Pila(){
    nodo *p;
    while(pTope){
        p = pTope;
        pTope = pTope->sig;
        delete p;
    }
}

void Pila::push(T dato){
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pTope;
    pTope = nuevo;
}

//POP = operacion destructiva = ver cuál elemento está en el tope
T Pila::pop(void){//pop = retirar un elemento
    nodo *aux;
    if(pTope){//existe al menos 1 elemento
        aux = pTope;
        pTope = pTope->sig;
        T elemento = aux->dato;//almaceno una copia
        delete aux;//borrar el nodo (el tope de mi pila)
        return elemento;//devuelvo la copia que hice
    }
    else
        return noValido;// Underflow!!!
}

//TOP = operacion NO destructiva = ver cual elemento está en el tope
T Pila::top(void){
    if(pTope)//existe al menos 1 elemento
        return pTope->dato;
    else//mi pila esta vacia
        return noValido;// Underflow!!!
}

bool Pila::empty(void){
    return (pTope == NULL);
    //devuelve TRUE si ptope es nulo
    //devuelve FALSE si ptope NO es nulo
}
