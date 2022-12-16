#include <iostream>
using namespace std;
int main(void)
{
cout << endl;
cout << "ADICION DE MEMORIA DINAMICA EN UN PROGRAMA" << endl << endl;
///////////////////////////
cout << "PRIMER EJEMPLO" << endl << endl;
float *p;
p = NULL;
if(!p) // Forma abreviada de p == NULL
cout << "El puntero esta a NULL" << endl;
else
cout << "El puntero NO está a NULL" << endl;
p = new float;
*p = 3.57;
cout << "Valor almacenado en el espacio creado: " << *p << endl << endl;
free(p);
p = NULL;
///////////////////////////
cout << "SEGUNDO EJEMPLO" << endl << endl;
float *q = new float(8.4); // Aquí estamos haciendo tres cosas a la vez:
// declarando un puntero, asignándole la
// dirección de un espacio de memoria creado
// dinámicamente y asignándole un valor inicial
// al espacio de memoria.
cout << "Valor almacenado en el espacio creado: " << *q << endl;
*q = 25.4;

cout << "Otro valor asignado a ese espacio: " << *q << endl << endl;
free(q);
q = NULL;
///////////////////////////
cout << "TERCER EJEMPLO" << endl << endl;
int *r = (int *) malloc(8 * sizeof(int)); // Crear un arreglo de
// ocho casillas de
// forma dinámica.

//int *r = new int[8];
for(int i = 0; i <= 8; i++)
*(r + i) = i * 2;
for(int i = 0; i <= 8; i++)
cout << *(r + i) << " ";
free(q);
//delete [] q;
cout << endl << endl;
return 0;
}