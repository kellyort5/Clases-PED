/*Elabore una función de tipo void que reciba tres argumentos por referencia,
 éstos deben ser punteros a variables enteras. Los tres valores son enviados desde el main hacia la función en cualquier orden,
 luego, la función se encargará de ordenarlos. Finalmente, desde el main se deberán mostrar ordenados en pantalla.
 El prototipo deberá ser: void ordenar(int *mayor, int *med, int *menor)*/
#include <iostream>
using namespace std;

void Ordenar(int, int, int, int *, int *, int *);

int main(void)
{
    int k, e, c, mayor, med, menor;

    cout << endl;
    cout << "ORDEN DE NUMEROS" << endl << endl;

    cout << "Por favor digite el valor del numero k: " << endl;
    cin >> k;
    cout << "Por favor digite el valor del numero e: " << endl;
    cin >> e;
    cout << "Por favor digite el valor del numero c: " << endl;
    cin >> c;

    Ordenar(k, e, c, &mayor, &med, &menor);

    cout << "El orden de los numeros es:  " << mayor << ", " << med << ", " << menor << ", " << endl;

    cout << endl;
    return 0;
}

void Ordenar(int x, int y, int z, int *mayor, int *med, int *menor)
{
    if(x > y && y > z)
    {
        *mayor = x;
        *med = y;
        *menor = z;
    }

    else if(x > y && y < z)
    {
        *mayor = x;
        *med = z;
        *menor = y;
    }

    else if(z > x && x > y)
    {
        *mayor = z;
        *med = x;
        *menor = y;
    }

    else if(z > x && x < y)
    {
        *mayor = z;
        *med = y;
        *menor = x;
    }

    else if(y > x && x > z)
    {
        *mayor = y;
        *med = x;
        *menor = z;
    }

    else if(y > x && x < z)
    {
        *mayor = y;
        *med = z;
        *menor = x;
    }
}
