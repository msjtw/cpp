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

    for(int i = 0; i < ILOSC && pojemnosc >= przedmioty[i].waga; i++){
        wynik += przedmioty[i].wartosc;
        pojemnosc -= przedmioty[i].waga;
    }

    cout << wynik; 
    return 0;
}