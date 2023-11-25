#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct el{
    int a, b;
    el *n;
};

int main(){
    srand(time(0));

    el *p, *a, *b;
    p = NULL;
    b = p;
    
    for(int i = 0; i < 10; i++){
        a = new el;
        a->n = NULL;
        if(p == NULL)
            p = a;
        else
            b->n = a;
        b = a;
        a->a = rand()%10 + 1;
        a->b = rand()%10 + 1;
    }

    el *c;

    while(p != NULL){
        int suma;
        cout << p->a << " * " << p->b << " = ";
        cin >> suma;
        if(suma != (p->a) * (p->b)){
            c = new el;
            c->a = p->a;
            c->b = p->b;
            c->n = NULL;
            b->n = c;
            b = c;
        }
        a = p;
        p = p->n;
        delete a;
    }

    return 0;
}