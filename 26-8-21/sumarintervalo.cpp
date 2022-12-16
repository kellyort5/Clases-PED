//arreglar
#include <iostream>
using namespace std;

void sumarIter(int, int);
void contarRec(int, int);


int main(void)
{
    int a, b;
    cout << endl;
    cout <<"SUMAR LOS ENTEROS ENTRE A Y B" <<endl<<endl;

    cout <<endl;
    cout<<"Digite los extremos del intervalo: "<<endl;
    cout<<"Limite inferior: ";
    cin>> a;
    cout <<"Limite superior: ";
    cin>> b;
    // versioin iterativa
    cout<< "La suma es: " << sumarIter(a,b);

    // versioin iterativa
    //contarRec(1, n);

    cout <<endl;
    return 0;
}

void contarRec(int i, int n)
{
    if( i <= 10){
        cout << i << endl;
        //i=i+1;
        contarRec(i, n);
    }
}

void contarIter(int n)
{
    int i;
    i=1;
    while(i <= n){
        cout << i <<endl;
        i=i+1;
    }
}
