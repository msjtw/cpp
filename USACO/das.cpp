#include <iostream>

using namespace std;

int tab[110];

bool czy(int sr, int p, int q){
    for(int i = p; i <= q; i++){
        if(tab[i] == sr)
            return true;
    }
    return false;
}

int main(){
    int p = 0;
    int ilosc = 0;
    cin >> p;
    for(int i = 0; i < p ;i++){
        cin >> tab[i];
    }
    for(int i = 0; i < p; i++){
        int suma = 0;
        int dz = 0;
        for(int j = i; j < p; j++){
            suma += tab[j];
            dz++;
            if(suma % dz == 0){
                if(czy(suma/dz,i,j))
                    ilosc++;
            }
        }
    }
    cout << ilosc;
}