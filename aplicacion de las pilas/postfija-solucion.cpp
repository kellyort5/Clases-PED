#include "postfija.hpp"

// Otras funciones a utilizar ---------------------
bool operand(char symb);
bool prcd(char a, char b);

// Programa principal ------------------------
int main(){
    string infija, postfija = "";
    cout << "Digite alguna expresion infija: ";
    getline(cin, infija);
    
    Pila expresion;
    for (int i = 0; i < infija.length(); i++) {
        char symb = infija[i];
        
        if(operand(symb))
            postfija += symb;
        else{
            while(!expresion.empty() && prcd(expresion.top(), symb)){
                char topsymb = expresion.pop();
                postfija += topsymb;
            }
            if(expresion.empty() || symb!=')')
                expresion.push(symb);
            else
                char topsymb = expresion.pop();
        }
    }
    while(!expresion.empty()){
        char topsymb = expresion.pop();
        postfija += topsymb;
    }
    
    cout << "Infija: " << infija << endl;
    cout << "Postfija: " << postfija << endl;

    return 0;
}

// Implementacion de funciones ------------------------
bool operand(char c){
    return (c=='0' || c=='1' || c=='2' || c=='3' || c=='4' ||
    c=='5' || c=='6' || c=='7' || c=='8' || c=='9') || 
    (c>='a' && c<='z') || (c>='A' && c<='Z');
}

bool prcd(char a, char b){
    if((a=='*'||a=='/') && (b=='+'||b=='-')) return true;
    else if((a=='+'||a=='-') && (b=='+'||b=='-')) return true;
    else if((a=='+'||a=='-') && (b=='*'||b=='/')) return false;
    else if(a=='(') return false;
    else if(b=='(') return false;
    else if(b==')') return true;
    else if(a=='$') return true;
    else return false;
}
