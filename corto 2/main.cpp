#include "doble.hpp"

int menu(){
    int opcion = 0;
    cout <<"\n\tBienvenido"<<endl<<endl;
    cout << "Por favor elija una opcion"<<endl;
    cout << "1) Agregar pedido." << endl;
    cout << "2) Mostrar cola de pedidos." << endl;
    cout << "3) Eliminar pedido." << endl;
    cout << "4) Salir." << endl;
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    ListaDoble saga;
    
    bool continuar = true;
    pedido p;
    pedido pref;
    do{
        switch(menu()){
            case 1: 
                p = solicitarpedido();
                saga.insertBack(p);
                cout << "Pedido almacenado exitosamente!" << endl;
                break;
            case 2: 
                saga.traversalForwardDirection();
                break;
                
            case 3: 
                if(saga.empty())
                    cout << "No hay pedidos por eliminar" << endl;
                else{
                    p = solicitarpedido();
                    saga.deleteItem(p);
                }
                break;

            case 4: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente de nuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
