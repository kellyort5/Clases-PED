#include <iostream>
using namespace std;

void contarIter(void);
int contarRec(int);


int main(void)
{
    cout << endl;
    cout <<"CONTAR DEL 1 AL 10" <<endl<<endl;

    // versioin iterativa
    contarIter();

    // versioin iterativa
    contarRec(1);

    cout <<endl;
    return 0;
}

int contarRec(int i)
{
    if( i <= 10){
        cout << i << endl;
        //i=i+1;
        contarRec(i+1);
    }
}

void contarIter(void)
{
    int i;
    i=1;
    while(i <= 10){
        cout << i <<endl;
        i=i+1;
    }
}
