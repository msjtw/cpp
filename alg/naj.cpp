// najlepsza suma w ciągu

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(0));
    int tab[10];
    for(int i = 0; i < 10; i++){
        tab[i] = rand()%21-10;
        cout << tab[i] << " ";
    }
    cout << endl;

    int p = 0, k = 0, suma = tab[0];
    int j = 0, sj = 0;
    
    for(int i = 0; i < 10; i++){
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