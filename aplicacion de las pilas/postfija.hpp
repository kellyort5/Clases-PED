#include <iostream>
#include <string>
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
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pTope;
    pTope = nuevo;
}

int Pila::pop(void){
    nodo *aux;
    if(pTope){
        aux = pTope;
        pTope = pTope->sig;
        int e = aux->dato;
        delete aux;
        return e;
    }
    return -1; // Underflow!
}

int Pila::top(void){
    if(pTope)
        return pTope->dato;
    return -1; // Underflow!
}

bool Pila::empty(void){
    return pTope == NULL;
}
