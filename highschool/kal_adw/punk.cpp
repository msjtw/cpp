#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct prz{
    int czas;
    int waga;
};

prz tab[110];

bool por(prz l, prz r){
    return l.czas*l.waga > r.czas*r.waga;
}

int main(){
    for(int i = 0; i < 100; i++){
        cin >> tab[i].czas >> tab[i].waga;
    }
    sort(tab,tab+100,por);
    long long int wynik = 0;
    int czas = 0;
    for(int i = 0; i < 100; i++){
        wynik += (tab[i].czas+czas)*tab[i].waga;
        czas += tab[i].czas;
    }

    cout << wynik;
}