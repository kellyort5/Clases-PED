#include "app1.hpp"

int main(void){
    cout << "ADMINISTRACIÓN DE LISTA LINEAL DOBLEMENTE ENLAZADA" << endl << endl;

    ListaDoble objListaDoble;
    cout << "Poblando..." << endl;
    objListaDoble.insertFront(1);
    objListaDoble.insertBack(2);
    objListaDoble.insertFront(0);
    cout << "Traversal in forward Direction:" << endl;
    objListaDoble.traversalForwardDirection();
    cout << "Traversal in reverse direction:" << endl;
    objListaDoble.traversalReverseDirection();
    
    return 0;
}
