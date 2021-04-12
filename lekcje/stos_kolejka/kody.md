## Stos

```c++
struct n{
    int w;
    n *p;
};

int main(){
    n *first, *a;
    first = NULL;
    //dodanie na koniec
    for(int i = 0; i < SIZE; i++){
        a = new n;
        cin >> a->w;
        a->p = first;
        first = a;
    }
    //usunięcie z końca
    while(first != NULL){
        cout << first->w;
        a = first;
        first = first->p;
        delete a;
    }
}
```

## Kolejka

```c++
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
```