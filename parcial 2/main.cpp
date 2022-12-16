#include "pila.hpp"

int menu(){
    int opcion = 0;
    cout << endl << "1) Agregar un estrato." << endl;
    cout << "2) Calcular grosor total." << endl;
    cout << "3) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    cout << "Cálculo de grosor de una sección de piel" << endl;
    Pila seccionPiel;
    Estrato p;
    
    bool continuar = true;
    do{
        switch(menu()){
            case 1: //Agregar un estrato
                p = solicitarEstrato();
                cout << "Estrato almacenado exitosamente!" << endl;
                break;
            case 2: //Calcular grosor
                seccionPiel.sumEstratos();
                break;
            case 3: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
