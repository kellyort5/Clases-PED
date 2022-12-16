#include <iostream>
using namespace std;

struct Node {
    int number;
    Node *next, *prev;
};

class Numbers {
    private:
        Node *front;
        Node *back;
    public:
        Numbers();
        void insert(int number);
        void print();
        void print(Node *it);
        void printReverse();
        void printReverse(Node *it);
        void remove(int ref);
        void remove(Node *it, int ref);
};

Numbers::Numbers () {
    front = nullptr;
    back = nullptr;
}

void Numbers::insert(int number) {
    Node *n = new Node;
    n->number = number;
    n->next = front;
    n->prev = back;
    if (front) {
        front->prev = n;
        back->next = n;
    } else
        back = n;
    front = n;
}

void Numbers::print() {
    if (!front) return;
    Node *it = front;
    print (it);
}

void Numbers::print(Node *it) {
    cout << it->number << endl;
    if (it == back) return;
    else {
        print(it->next);
    }
}

void Numbers::printReverse() {
    if (!back) return;
    Node *it = back;
    printReverse (it);
}

void Numbers::printReverse(Node *it) {
    cout << it->number << endl;
    if (it == front) return;
    else {
        printReverse(it->prev);
    }
}

void Numbers::remove(int ref) {
    if (!front) return;
    if (front->number == ref && back->number == ref) {
        front = back = nullptr;
    } else {
        Node *it = front;
        remove(it, ref);
    }
}

void Numbers::remove(Node *it,int ref) {
    if (it->number == ref) {
        Node *aux = it;
        it = it->prev;
        it->next = aux->next;
        aux->next->prev = it;
        if (aux == front) {
            front = aux->next;
            front->prev = back;
        }
        else if (aux == back) {
            back = it;
            back->next = front;
        }
        delete aux;
    }
    if (it == back) {
        // if (it->number == ref) {
        //     Node *aux = it;
        //     it = it->prev;
        //     it->next = aux->next;
        //     aux->next->prev = it;
        //     back = it;
        //     delete aux;
        // } else {
        //     cout << "no hay" << endl;
        // }
        return;
    } else {
        // if (it->number == ref) {
        //     Node *aux = it;
        //     it = it->prev;
        //     it->next = aux->next;
        //     aux->next->prev = it;
        //     if (aux == front) front = aux->next;
        //     delete aux;
        // }
        remove(it->next, ref);
    }
}

int main () {
    Numbers list;
    int n = 10;
    for (int i = 0; i < n; i++) {
        list.insert(i);
    }
    list.printReverse();
    for (int i = 0; i < n-4; i++) {
        list.remove(i);
    }
    cout << "--" << endl;
    list.printReverse();

    return 0;
}