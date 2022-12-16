#include <iostream>
using namespace std;

void contarIter(int);
void contarRec(int);


int main(void)
{
    int n;
    cout << endl;
    cout <<"CONTAR DEL N A 1" <<endl<<endl;

    cout<<"En que numero comenzar? ";
    cin>>n;

    // versioin iterativa
    contarIter(n);

    // versioin iterativa
    contarRec(n);

    cout <<endl;
    return 0;
}

void contarRec(int n)
{
    if( n >= 1){
        cout << n << endl;
        n=n-1;
        contarRec(n);
    }
}

void contarIter(int n)
{
    while(n >= 1){
        cout << n <<endl;
        n=n-1;
    }
}
