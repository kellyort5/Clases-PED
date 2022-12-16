#include "templantes.hpp"

int main(){
    Pila vehiculos;
    
    Placa A = {'P',123};
    vehiculos.push(A);
    
    Placa B = {'N',456};
    vehiculos.push(B);
    
    Placa C = {'B',789};
    vehiculos.push(C);
    
    while(!vehiculos.empty()){
        Placa p = vehiculos.top();
        cout << "Tipo: " << p.tipo;
        cout << " Numero: " << p.numero << endl;
        vehiculos.pop();
    }

    return 0;
}
