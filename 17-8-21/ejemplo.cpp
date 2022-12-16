#include <iostream>
using namespace std;

int noventaMinutos(int *s1, int *s2);
int tiempoExtra(int **d1, int **d2);
int tirospenales(int ***t1, int ***t2);

int main(){
    int golesA = 0, golesB = 0;
    if(noventaMinutos(&golesA, &golesB) == 1){
        cout << "Gana el Equipo A" << endl;
        cout << "Cantidad total de goles: " << golesA << endl;
    }
    else{
        cout << "Gana el Equipo B" << endl;
        cout << "Cantidad total de goles: " << golesB << endl;
    }

    return 0;
}

int noventaMinutos(int *s1, int *s2){//punteros simples
    cout << "90 minutos" << endl;
    int golesA = 0, golesB = 0;//varibles locales
    cout << "Goles de A: ";
    cin >> golesA;
    *s1 += golesA;
    cout << "Goles de B: ";
    cin >> golesB;
    *s2 += golesB;
    
    if (*s1 > *s2)
        return 1;
    else if (*s1 < *s2)
        return 2;
    else
        return tiempoExtra(&s1, &s2);//envio la direccion de S1 y S2
}

int tiempoExtra(int **d1, int **d2){//punteros dobles
    cout << "tiempo extra" << endl;
    int golesA = 0, golesB = 0;//varibles locales
    cout << "Goles de A: ";
    cin >> golesA;
    **d1 += golesA;
    cout << "Goles de B: ";
    cin >> golesB;
    **d2 += golesB;
    
    if (**d1 > **d2)
        return 1;
    else if (**d1 < **d2)
        return 2;
    else
        return tirospenales(&d1, &d2);//envio la direccion de D1 y D2
}

int tirospenales(int ***t1, int ***t2){//punteros dobles
    cout << "tiros penales" << endl;
    int golesA = 0, golesB = 0;//varibles locales
    cout << "Goles de A: ";
    cin >> golesA;
    ***t1 += golesA;
    cout << "Goles de B: ";
    cin >> golesB;
    ***t2 += golesB;
    
    if (***t1 > ***t2)
        return 1;
    else
        return 2;
}

