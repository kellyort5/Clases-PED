#include "infija.hpp"
#include <cmath>

// Otras funciones a utilizar ---------------------
bool operand(char symb);
float oper(char symb, float a, float b);

// Programa principal ------------------------
int main(){
    string postfija;
    cout << "Digite alguna expresion postfija: ";
    getline(cin, postfija);
    
    Pila expresion;
    for (int i = 0; i < postfija.length(); i++) {
        char symb = postfija[i];
        
        if(operand(symb)){
            int digito = symb  - '0';
            expresion.push(digito);
        }
        else{
            float oper2 = expresion.pop();
            float oper1 = expresion.pop();
            float value = oper(symb, oper1, oper2);
            expresion.push(value);
        }
    }
    
    cout << "Resultado: " << expresion.pop() << endl;

    return 0;
}

// Implementacion de funciones ------------------------
bool operand(char c){
    return (c=='0' || c=='1' || c=='2' || c=='3' || c=='4' ||
    c=='5' || c=='6' || c=='7' || c=='8' || c=='9');
}

float oper(char symb, float a, float b){
    if(symb=='+') return a + b;
    else if(symb=='-') return a - b;
    else if(symb=='*') return a * b;
    else if(symb=='/') return a / b;
    else if(symb=='$') return pow(a, b);
    else return -1;
}
