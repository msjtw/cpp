#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 20;

void merge(int p, int g, int q, int t[]){
    int a = p, b = g, tab[SIZE] {};
    int i = p;
    while(a < g && b < q)
        tab[i++] = (t[a] < t[b] ? t[a++] : t[b++]);
    while(a < g)
        tab[i++] = t[a++];
    while(b < q)
        tab[i++] = t[b++];
    for(int k = p; k < q; k++)
        t[k] = tab[k];
}

void mergesort(int p, int q, int t[]){
    if(p+1 != q){
        int m = (p+q)/2;
        mergesort(p, m, t);
        mergesort(m, q, t);
        merge(p, m, q, t);
    }
}

int main(){
    srand(time(0));

    int t[SIZE];
    for(int i = 0; i < SIZE; i++)
        t[i] = rand()%100;

    mergesort(0, SIZE, t);

    for(int i = 0; i < SIZE; i++){
        cout << t[i] << " ";
    }

    return 0;
}