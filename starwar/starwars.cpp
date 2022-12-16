#include "star.hpp"

int menu(){
    int opcion = 0;
    cout << endl << "1) Agregar una precuela." << endl;
    cout << "2) Agregar una secuela." << endl;
    cout << "3) Mostrar saga de inicio a fin." << endl;
    cout << "4) Mostrar saga de fin a inicio." << endl;
    cout << "5) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    ListaDoble saga;
    
    bool continuar = true;
    Pelicula p;
    do{
        switch(menu()){
            case 1: //Agregar una precuela
                p = solicitarPelicula();
                saga.insertFront(p);
                cout << "Precuela almacenada exitosamente!" << endl;
                break;
            case 2: //Agregar una secuela
                p = solicitarPelicula();
                saga.insertBack(p);
                cout << "Secuela almacenada exitosamente!" << endl;
                break;
            case 3: //Mostrar saga de inicio a fin
                saga.traversalForwardDirection();
                break;
            case 4: //Mostrar saga de fin a inicio
                saga.traversalReverseDirection();
                break;
            case 5: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
