#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct punkt{
    int x;
    int y;
};

struct pret{
    punkt a;
    punkt b;
    long long int dlugosc;
};

struct pret_v2{
    pret zebrowanie;
    int id;
};


int iloczyn(punkt a, punkt b, punkt c){
    return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);
}
bool pkt_na(punkt a, punkt b, punkt c){
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}
bool przecina(punkt a, punkt b, punkt c, punkt d){
    int il1 = iloczyn(c, d, a);
    int il2 = iloczyn(c, d, b);
    int il3 = iloczyn(a, b, c);
    int il4 = iloczyn(a, b, d);

    if((il1 > 0 && il2 < 0 || il1 < 0 && il2 > 0) && (il3 > 0 && il4 < 0 || il3 < 0 && il4 > 0))
        return 1;
    if((il1 == 0 && pkt_na(c, d, a)) || (il2 == 0 && pkt_na(c, d, b)) || (il3 == 0 && pkt_na(a, b, c)) || (il4 == 0 && pkt_na(a, b, d)))
        return 1;

    return 0;
}

long long int pow2(long long int a){
    return a*a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long int wynik = 0;
    bool grac1 = true;
    vector <pret> prety;
    while(true){
        grac1 = !grac1;
        pret rzut;
        cin >> rzut.a.x >> rzut.a.y >> rzut.b.x >> rzut.b.y;
        if(rzut.a.x == 0 && rzut.a.y == 0 && rzut.b.x == 0 && rzut.b.y == 0)
        break;
        rzut.dlugosc=pow2(rzut.b.x-rzut.a.x)+pow2(rzut.b.y-rzut.a.y);
        if(prety.size() > 0){
            vector <pret_v2> przecinajace;
            for(int i = 0; i < prety.size(); i++){
                if(przecina(rzut.a,rzut.b,prety[i].a,prety[i].b)){
                    pret_v2 a;
                    a.zebrowanie = prety[i];
                    a.id = i;
                    przecinajace.push_back(a);
                }
            }
            if(przecinajace.size() > 0){
                pret_v2 nja = przecinajace[0];
                for(int i = 0; i <  przecinajace.size(); i++){
                    if(przecinajace[i].zebrowanie.dlugosc > nja.zebrowanie.dlugosc){
                        nja = przecinajace[i];
                    }
                }
                if(grac1){
                    wynik += nja.zebrowanie.dlugosc + rzut.dlugosc;
                }
                else{
                    wynik -= nja.zebrowanie.dlugosc + rzut.dlugosc;
                }
                prety.erase(prety.begin()+nja.id);
            }
            else{
                prety.push_back(rzut);
            }
        }
        else{
            prety.push_back(rzut);
        }
    }
    cout << abs(wynik);

    return 0;
}