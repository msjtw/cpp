#include <iostream>

using namespace std;

const int SIZE = 10;

struct n{
    int w;
    n *n;
};

int main(){
    n *first, *a, *last;
    first = NULL;
    last = first;
    // dodanie na koniec
    for(int i = 0; i < SIZE; i++){
        a = new n;
        a->n = NULL;
        cin >> a->w;
        if(first == NULL)
            first = a;
        else
            last->n = a;
        last = a;
    }
    // usunięcie z początku
    while(first != NULL){
        cout << first->w;
        a = first;
        first = first->n;
        delete a;
    }
}