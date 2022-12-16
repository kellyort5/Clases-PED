#include "star3.hpp"

int menu(){
    int opcion = 0;
    cout << endl << "1) Agregar una precuela." << endl;
    cout << "2) Agregar una secuela." << endl;
    cout << "3) Mostrar saga de inicio a fin." << endl;
    cout << "4) Mostrar saga de fin a inicio." << endl;
    cout << "5) Eliminar película." << endl;
    cout << "6) Buscar títulos (independientemente del anio)." << endl;
    cout << "7) Buscar si hay película en un anio dado." << endl;
    cout << "8) Buscar película." << endl;
    cout << "9) Agregar película después de referencia." << endl;
    cout << "10) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    ListaDoble saga;
    
    bool continuar = true;
    Pelicula p;
    Pelicula pref;
    string tituloref = "";
    int anioref = 0;
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
                    cout << "No hay películas por eliminar" << endl;
                else{
                    p = solicitarPelicula();
                    saga.deleteItem(p);
                }
                break;
            case 6: //Buscar una película
                if(saga.empty())
                    cout << "No hay películas por buscar!" << endl;
                else{
                    cout << "Titulo: ";
                    getline(cin, tituloref);
                    if(saga.searchItemByTitle(tituloref))
                        cout << "La película SI se encontró :)" << endl;
                    else
                        cout << "La película NO se encontró :(" << endl;
                }
                break;
            case 7: //Buscar una película
                if(saga.empty())
                    cout << "No hay películas por buscar!" << endl;
                else{
                    cout << "Anio de lanzamiento: ";
                    cin >> anioref; cin.ignore();
                    if(saga.searchItemByYear(anioref))
                        cout << "La película SI se encontró :)" << endl;
                    else
                        cout << "La película NO se encontró :(" << endl;
                }
                break;
            case 8: //Buscar una película
                if(saga.empty())
                    cout << "No hay películas por buscar!" << endl;
                else{
                    p = solicitarPelicula();
                    if(saga.searchItemExact(p))
                        cout << "La película SI se encontró :)" << endl;
                    else
                        cout << "La película NO se encontró :(" << endl;
                }
                break;
            case 9: //Agregar una película después de una referencia
                cout << "<Película a insertar>" << endl;
                p = solicitarPelicula();
                cout << "<Película de referencia>" << endl;
                pref = solicitarPelicula();
                saga.insertAfter(p, pref);
                cout << "Película almacenada exitosamente!" << endl;
                break;
            case 10: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
