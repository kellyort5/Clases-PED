#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

class Pila{
    private:
        nodo *pTope;
    public:
        Pila();
        ~Pila();
        void push(int);
        int pop(void);
        int top(void);
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

void Pila::push(int dato){
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pTope;
    pTope = nuevo;
}

//POP = operacion destructiva = ver cuál elemento está en el tope
int Pila::pop(void){//pop = retirar un elemento
    nodo *aux;
    if(pTope){//existe al menos 1 elemento
        aux = pTope;
        pTope = pTope->sig;
        int elemento = aux->dato;//almaceno una copia
        delete aux;//borrar el nodo (el tope de mi pila)
        return elemento;//devuelvo la copia que hice
    }
    else
        return -1;// Underflow!!!
}

//TOP = operacion NO destructiva = ver cual elemento está en el tope
int Pila::top(void){
    if(pTope)//existe al menos 1 elemento
        return pTope->dato;
    else//mi pila esta vacia
        return -1;// Underflow!!!
}

bool Pila::empty(void){
    return (pTope == NULL);
    //devuelve TRUE si ptope es nulo
    //devuelve FALSE si ptope NO es nulo
}
