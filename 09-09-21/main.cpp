#include "lista.hpp"
using namespace std;

int menu(){
    int opcion = 0;
    cout << "1) Hacer una transaccion." << endl;
    cout << "2) Mostrar el historial." << endl;
    cout << "3) Calcular el balance total." << endl;
    cout << "4) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void)
{
    cout << "Bienvenido a la C++ Wallet" << endl;

    // Crear la wallet
    ListaSimple miBilletera(0.0005, "monto inicial");//-->5
    
    bool continuar = true;
    double monto = 0;
    string d = "";
    do{
        switch(menu()){
            case 1: //Hacer una transaccion
                cout << "Digite el monto de la transaccion: ";
                cin >> monto; cin.ignore();
                cout << "Descripcion: ";
                getline(cin, d);
                miBilletera.insInicio(monto, d);
                cout << "Transaccion almacenada exitosamente!" << endl;
                break;
            case 2: //Mostrar el historial
                miBilletera.mostrarListaIter();
                break;
            case 3: //Calcular el balance total
                cout << "Balance final: " << miBilletera.calcularBalance() << " BT" << endl;
                break;
            case 4: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    /*// Hacer un par de transacciones
    miBilletera.insInicio(0.0002);//-->2-->5
    miBilletera.insInicio(-0.0003);//-->(-3)-->2-->5
    miBilletera.insInicio(0.0002);//-->2-->(-3)-->2-->5
    
    // Mostrar el resultado
    miBilletera.mostrarListaIter();
    cout << "Balance final: " << miBilletera.calcularBalance() << " BT" << endl;*/
    cout << endl;
    return 0;
}
