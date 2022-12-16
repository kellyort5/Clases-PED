#include <iostream>
using namespace std;

struct nodo
{
    int dato;
    nodo *hijoizq;  // puntero al subarbol izquierdo
    nodo *hijodere; // puntero al subarbol derecho
};

class Abb
{
private:
    nodo *pAbb;

public:
    Abb();
    ~Abb();
    void insertar(void);
    void insnodoAbb(nodo **, int);
    void mostrarPreorden(void);
    void mostrarpre(nodo *);
    void mostrarInorden(void);
    void mostrarIn(nodo *);
    void mostrarPostorden(void);
    void mostrarpost(nodo *);
    void buscarnodo(int);
    void buscar(nodo *, int);
};

Abb::Abb(void)
{
    pAbb = NULL;
}

Abb::~Abb(void)
{
    cout << "Destructor ejecutandose" << endl;
}

void Abb::insertar(void)
{
    int dato;
    char resp;

    do
    {
        cout << "Desea digitar un dato? ";
        cin >> resp;
        if (resp == 's')
        {
            cout << "Digite el dato: " << endl;
            cin >> dato;
            insnodoAbb(&pAbb, dato);
        }
    } while (resp == 's');
}

void Abb::insnodoAbb(nodo **p, int dato)
{
    if (!(*p))
    {
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->hijoizq = NULL;
        (*p)->hijodere = NULL;
    }
    else
    {
        if (dato < (*p)->dato)
        {
            insnodoAbb(&((*p)->hijoizq), dato);
        }
        else
        {
            if (dato > (*p)->dato)
            {
                insnodoAbb(&((*p)->hijodere), dato);
            }
            else
            {
                // se le llama llave a los datos de los arboles(como el dui, nit, etc)
                cout << "La llave ya esta en el arbol" << endl
                     << endl;
            }
        }
    }
}

void Abb::buscarnodo(int dato)
{
    buscar(pAbb, dato);
}

void Abb::buscar(nodo *p, int dato)
{
    if (!p)
    {
        cout << "El dato no esta en el arbol" << endl;
    }
    else
    {
        if (dato, p->dato)
        {
            buscar(p->hijoizq, dato);
        }
        else
        {
            if (dato > p->dato)
            {
                buscar(p->hijodere, dato);
            }
            else
            {
                cout << "Dato encontrado" << endl;
            }
        }
    }
}

void Abb::mostrarInorden(void)
{
    mostrarIn(pAbb);
}

void Abb::mostrarIn(nodo *p)
{
    if (p)
    {
        mostrarIn(p->hijoizq);
        cout << p->dato << "  ";
        mostrarIn(p->hijodere);
    }
}
void Abb::mostrarPreorden(void)
{
    mostrarpre(pAbb);
}

void Abb::mostrarpre(nodo *p)
{
    if (p)
    {
        cout << p->dato << "  ";
        mostrarpre(p->hijoizq);
        mostrarpre(p->hijodere);
    }
}

void Abb::mostrarPostorden(void)
{
    mostrarpost(pAbb);
}

void Abb::mostrarpost(nodo *p)
{
    if (p)
    {
        cout << p->dato << "  ";
        mostrarpost(p->hijoizq);
        mostrarpost(p->hijodere);
    }
}

int main(void)
{
    cout << endl;
    cout << "ADMINISTRACION DE ARBOL BINARIO DE BUSQUEDA" << endl;

    Abb objAbb;
    cout << "Incertar datos en el arbol: " << endl
         << endl;
    objAbb.insertar();
    cout << endl
         << "Mostrando en inorden: " << endl;
    objAbb.mostrarInorden();
    cout << endl
         << "Mostrando en preorden: " << endl;
    objAbb.mostrarPreorden();
    cout << endl
         << "Mostrando en postorden: " << endl;
    objAbb.mostrarPostorden();
    cout<<"Busquemos un dato"<<endl;
    int dato;
    cout<<"Digite el dato a buscar: "<<endl;
    cin >> dato;
    objAbb.buscarnodo(dato);
    cout << endl;
    return 0;
}