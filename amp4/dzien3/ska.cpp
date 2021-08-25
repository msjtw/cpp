#include <iostream>

using namespace std;

int main(){
    int liczb;
    cin >> liczb;
    int tab[100007] {};
    for(int i = 0; i < liczb; i++){
        cin >> tab[i];
    }

    int tur = 1;
    int skok = 1;
    int k = 0;
    while(k != liczb-1){
        k += skok;
        skok += tab[k];
        tab[k] = 0;
        if( k >= liczb){
            skok = 1;
            k = 0;
            tur++;
        }
    }

    cout << tur;

    return 0;
}