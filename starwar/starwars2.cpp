#include "star2.hpp"

int menu(){
    int opcion = 0;
    cout << endl << "1) Agregar una precuela." << endl;
    cout << "2) Agregar una secuela." << endl;
    cout << "3) Mostrar saga de inicio a fin." << endl;
    cout << "4) Mostrar saga de fin a inicio." << endl;
    cout << "5) Eliminar pelicula." << endl;
    cout << "6) Buscar pelicula." << endl;
    cout << "7) Agregar pelicula despues de referencia." << endl;
    cout << "8) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    ListaDoble saga;
    
    bool continuar = true;
    Pelicula p;
    Pelicula pref;
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
            case 5: //Eliminar una película
                if(saga.empty())
                    cout << "No hay peliculas por eliminar" << endl;
                else{
                    p = solicitarPelicula();
                    saga.deleteItem(p);
                }
                break;
            case 6: //Buscar una película
                if(saga.empty())
                    cout << "No hay peliculas por buscar" << endl;
                else{
                    p = solicitarPelicula();
                    cout << "Dicha pelicula " << (saga.searchItem(p)?"SI":"NO");
                    cout << " se encuentra en la saga." << endl;
                }
                break;
            case 7: //Agregar una película después de referencia
                cout << "<Pelicula a insertar>" << endl;
                p = solicitarPelicula();
                cout << "<Pelicula de referencia>" << endl;
                pref = solicitarPelicula();
                saga.insertAfter(p, pref);
                cout << "Pelicula almacenada exitosamente!" << endl;
                break;
            case 8: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente de nuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
