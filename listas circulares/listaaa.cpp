#include <iostream>
using namespace std;

struct Node {
    int number;
    Node *next;
};

class Circular_List {
    private:
        Node *front;
        Node *back;
    public:
        Circular_List();
        ~Circular_List();
        void insert(int number);
        void insertUpward(int number);
        void update(int number, int ref);
        void remove(int ref);
        void print();
};

Circular_List::~Circular_List() {
    Node *aux = front;
    front = front->next;
    while (front != aux) {
        Node *aux2 = front;
        front = front->next;
        delete aux2;
    }
    delete aux;
    front = nullptr;
}

Circular_List::Circular_List() {
    front = nullptr;
    back = nullptr;
}

void Circular_List::insert(int number) {
    // Node *n = new Node;
    // n->number = number;

    // if (!front) back = n;
    // else n->next = front;
    
    // front = n;
    // back->next = n;
    Node *n = new Node;
    n->number = number;
    n->next = front;
    if (!front) {
        front = n;
        n->next = front;
    } else {
        Node *aux = front;
        while (aux->next != front) {
            aux = aux->next;
        }
        aux->next = n;
        front = n;
    }
}

void Circular_List::insertUpward(int number) {
    if (!front) insert(number);
    else {
        Node *it = front;

        while (it->next != front && it->number < number && it->next->number < number) {
            it = it->next;
        }
        if (it == front && it->number > number) insert(number);
        else {
            Node *n = new Node;
            n->number = number;

            if (it->next == front) back = n;
            n->next = it->next;
            it->next = n;
        }

    }
}

void Circular_List::print() {
    Node *it = front;
    do {
        cout << it->number << endl;
        it = it->next;
    } while (it != front);
}

void Circular_List::update(int number, int ref) {
    Node *it = front;
    do {
        if (it->number == ref)
            it->number = number;
        it = it->next;
    } while (it != front);
}

void Circular_List::remove(int ref) {
    Node *it = front;
        cout << "r" << endl;
    do {
        // cout << it->number << endl;
        if (it->next->number == ref) {
            cout << it->next->number << endl;
            Node *aux = it->next; 
            it->next = aux->next;
            if (it == front && aux == front) {
                delete front;
                front = nullptr;
            } else
                delete aux;
        }
        it = it->next;
    } while (it != front);
    cout <<"--" << endl;
}

int main () {
    Circular_List list;
    list.insert(0);
    // list.insert(2);
    // list.insert(10);
    // list.insert(5);
    // list.insert(0);
    // list.insert(7);
    // list.insert(2);
    // list.insert(0);
    list.remove(0);
    list.print();
    return 0;
}
