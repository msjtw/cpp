// najlepsza suma w ciągu

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 20;

int main(){
    srand(time(0));
    int tab[SIZE];
    for(int i = 0; i < SIZE; i++){
        tab[i] = rand()%21-10;
        cout << tab[i] << " ";
    }
    cout << endl;

    int p = 0, k = 0, suma = tab[0];
    int j = 0, sj = 0;
    
    for(int i = 0; i < SIZE; i++){
        if(tab[i] > sj+tab[i]){
            sj = tab[i];
            j = i;
        }
        else{
            sj += tab[i];
        }
        if(sj > suma){
            suma = sj;
            p = j;
            k = i;
        }
    }
    cout << p << " " << k << " " << suma;
}