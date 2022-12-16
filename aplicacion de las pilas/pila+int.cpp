#include "pila+.hpp"

int main(){
    Pila expresion;
    expresion.push(1);
    expresion.push(2);
    expresion.push(4);
    
    while(!expresion.empty()){
        //cout << expresion.pop() << endl;
        cout << expresion.top() << endl;
        expresion.pop();
    }

    return 0;
}