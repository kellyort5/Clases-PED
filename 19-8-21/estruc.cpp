#include<iostream>

using namespace std;

struct estructura{
int campo1;
float campo2;
char campo3;
};

int main(void)
{
estructura miVariable, tuVariable, *p;

cout << endl;
cout << "PRIMER EJEMPLO DE USO DE UNA ESTRUCTURA" << endl << endl;

p = &miVariable;

p->campo1 = 5;
(*p).campo2 = 37.54;
miVariable.campo3 = 't';

tuVariable = miVariable;

cout << "El campo 1 de miVariable es: " << miVariable.campo1 << endl;
cout << "El campo 2 de miVariable es: " << p->campo2 << endl;
cout << "El campo 3 de miVariable es: " << (*p).campo3 << endl;

cout << endl;

cout << "El campo 1 de tuiVariable es: " << tuVariable.campo1 << endl;
cout << "El campo 2 de tuVariable es: " << tuVariable.campo2 << endl;
cout << "El campo 3 de tuVariable es: " << tuVariable.campo3 << endl;

cout << endl;

return 0;
}