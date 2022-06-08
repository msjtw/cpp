#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 1000;

void selectionsort(int t[]){
    for(int i = 0; i < SIZE-1; i++){
        int poz = i;
        for(int k = i+1; k < SIZE; k++){
            if(t[k] < t[poz])
                poz = k;
        }
        swap(t[poz], t[i]);
    }
}

void insertionsort(int t[]){
    for(int i = 0 ; i < SIZE-1; i++){
        for(int k = i+1; k > 0; k--)
            if(t[k-1] > t[k])
                swap(t[k-1], t[k]);
    }
}

void bubblesort(int t[]){
    for(int i = 0 ; i < SIZE-1; i++)
        for(int k = 0; k < SIZE-1; k++)
            if(t[k] > t[k+1])
                swap(t[i], t[k+1]);
}

void mysort(int t[]){
    for(int i = 0; i < SIZE; i++){
        for(int k = i+1; k < SIZE; k++){
            if(t[i] > t[k])
                swap(t[k], t[i]);
        }
    }
}

int main(){
    srand(time(0));

    for(int k = 0; k < 10000; k++){

        int t[SIZE];
        for(int i = 0; i < SIZE; i++)
            t[i] = rand()%10000;

        mysort(t);

        for(int i = 1; i < SIZE; i++){
            if(t[i-1] > t[i]){
                cout << "no chyba nie";
                return 0;
            }
        }
            cout << k << "   jest git" << endl;
    }


    return 0;
}