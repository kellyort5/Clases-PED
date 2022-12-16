#include <iostream>

using namespace std;

union miUnion{
int entero;
float real;
char car;
};

struct miEstructura{
int cualEs;
miUnion dato;
};

int main(void)
{
miEstructura var;

cout << endl;
cout << "EJEMPLO CON UNION" << endl << endl;

cout << "Desea un (1) entero / (2) real / (3) caracter?: ";
cin >> var.cualEs;

switch(var.cualEs){
case 1:
cout << "Digite el entero: ";
cin >> var.dato.entero;
break;

case 2:
cout << "Digite el real: ";
cin >> var.dato.real;
break;
case 3:
cout << "Digite el caracter: ";
cin >> var.dato.car;
}

cout << endl << endl;

cout << "El dato almacenado es: ";
switch(var.cualEs){
case 1:
cout << var.dato.entero << endl;
break;
case 2:
cout << var.dato.real << endl;
break;
case 3:
cout << var.dato.car << endl;
}

cout << endl;

return 0;
}