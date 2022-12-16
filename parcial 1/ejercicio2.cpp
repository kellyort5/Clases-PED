/*Elabore la función recursiva int sumaRec(void), 
que lee recursivamente números enteros desde teclado y realiza su suma. 
Esto lo realiza hasta que se digita el valor -1. La función debe devolver la suma calculada a la función main,
la cual recibe e imprime la suma calculada.*/
#include <iostream>
using namespace std;

int Suma(){
    int n;
    cout << endl;
    cout << "Digite un numero o -1 para salir: "; cin >> n;
    if(n == -1) return 0;
    else return n + Suma();
}

int main()
{
    int n = Suma();
    cout << "El resultado es: " << n;
    return 0;
}