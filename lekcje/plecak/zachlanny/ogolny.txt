#include <iostream>
#include <algorithm>

using namespace std;

struct przdmiot{
    double waga;
    double wartosc;
};

const int ILOSC = 6;

przdmiot przedmioty[ILOSC];

bool por(przdmiot left, przdmiot right){
    return left.wartosc/left.waga > right.wartosc/right.waga;
}

int main(){
    int pojemnosc;
    cin >> pojemnosc;
    for(int i = 0; i < ILOSC; i++){
        cin >> przedmioty[i].wartosc >> przedmioty[i].waga;
    }

    sort(przedmioty, przedmioty+ILOSC, por);

    int wynik = 0;

    int i = 0;
    while(i < ILOSC){
        while(pojemnosc >= przedmioty[i].waga){
            wynik += przedmioty[i].wartosc;
            pojemnosc -= przedmioty[i].waga;
        }
        i++;
    }

    cout << wynik; 
    return 0;
}