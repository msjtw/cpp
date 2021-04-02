// Stanisław Fiedler VIII LO Poznań

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct wynik{
    int id = 0;
    int dop = 0;
};

wynik rogale[3];
wynik drozdzowki[3];
wynik paczki[3];

void dod(wynik tab[], int koszt, int ide){
    if(koszt < tab[2].dop){
        if(koszt < tab[1].dop){
            if(koszt < tab[0].dop){
                tab[2].dop = tab[1].dop;
                tab[2].id = tab[1].id;
                tab[1].dop = tab[0].dop;
                tab[1].id = tab[0].id;
                tab[0].dop = koszt;
                tab[0].id = ide;
            }
            else{
                tab[2].dop = tab[1].dop;
                tab[2].id = tab[1].id;
                tab[1].dop = koszt;
                tab[1].id = ide;
            }
        }
        else{
            tab[2].dop = koszt;
            tab[2].id = ide;
        }
    }
}

bool po = false, dr = false, ro = false;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i =0; i < 3; i++){
        rogale[i].dop = INT_MAX;
        drozdzowki[i].dop = INT_MAX;
        paczki[i].dop = INT_MAX;
    }

    long long int wynik = 0;
    long long int ilosc, p, d, r, kp, kd, kr;
    cin >> ilosc;
    while(ilosc--){
        cin >> d >> p >> r;
        if(d > 0)
            dr = true;
        if(p > 0)
            po = true;
        if(r > 0)
            ro = true;
        kp = d+r;
        kd = p+r;
        kr = d+p;
        int mi = min(kp,min(kd,kr));
        wynik += mi;
        dod(rogale, kr-mi, ilosc);
        dod(paczki, kp-mi, ilosc);
        dod(drozdzowki, kd-mi, ilosc);
    }
    if(!po){
        for(int i = 0; i < 3; i++){
            paczki[i].dop = 0;
            paczki[i].id = -1;
        }
    }
    if(!dr){
        for(int i = 0; i < 3; i++){
            drozdzowki[i].dop = 0;
            drozdzowki[i].id = -1;
        }
    }
    if(!ro){
        for(int i = 0; i < 3; i++){
            rogale[i].dop = 0;
            rogale[i].id = -1;
        }
    }
    

    int dop = INT_MAX;
    bool weszlo = false;
    for(int a = 0; a < 3; a++){
        for(int b = 0; b < 3; b++){
            for(int c = 0; c < 3; c++){
                if(rogale[a].id != paczki[b].id && rogale[a].id != drozdzowki[c].id && paczki[b].id != drozdzowki[c].id){
                    dop = min(dop, (rogale[a].dop + paczki[b].dop + drozdzowki[c].dop));
                    weszlo = true;
                }
            }
        }
    }
    if(weszlo)
        wynik += dop;

    cout << wynik;

    return 0;
}