#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 200000;

int tab[SIZE+7] {};

void merge(int left, int mid, int right, int t[]){
    int a = left, b = mid;
    int i = left;
    while(a < mid && b < right)
        tab[i++] = (t[a] < t[b] ? t[a++] : t[b++]);
    while(a < mid)
        tab[i++] = t[a++];
    while(b < right)
        tab[i++] = t[b++];
    for(int k = left; k < right; k++)
        t[k] = tab[k];
}

void mergesort(int left, int right, int t[]){
    if(left+1 != right){
        int m = (left+right)/2;
        mergesort(left, m, t);
        mergesort(m, right, t);
        merge(left, m, right, t);
    }
}

int main(){
    srand(time(0));

    int t[SIZE+7];
    for(int i = 0; i < SIZE; i++)
        t[i] = rand()%100;

    mergesort(0, SIZE, t);

    for(int i = 0; i < SIZE; i++){
        cout << t[i] << " ";
    }

    return 0;
}