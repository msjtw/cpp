#include <iostream>

using namespace std;

struct rzecz{
    int waga;
    int wartosc;
};

struct kom{
    int wartosc;
    int ost;
};

rzecz przedmioty[25];

kom tab[25][1010];

int main(){
    int ilosc, dop;
    cin >> ilosc >> dop;
    for(int i = 0; i < ilosc; i++){
        cin >> przedmioty[i+1].waga;
    }
    for(int i = 0; i < ilosc; i++){
        cin >> przedmioty[i+1].wartosc;
    }

    for(int i = 1; i <= ilosc; i++){
        for(int j = 0; j <= dop; j++){
            if(j-przedmioty[i].waga >= 0){
                if(tab[i-1][j].wartosc > tab[i][j-przedmioty[i].waga].wartosc+przedmioty[i].wartosc){
                    tab[i][j] = tab[i-1][j];
                }
                else{
                    tab[i][j].wartosc = tab[i][j-przedmioty[i].waga].wartosc+przedmioty[i].wartosc;
                    tab[i][j].ost = i;
                }
            }
            else{
                tab[i][j] = tab[i-1][j];
            }
            
        }
        
    }

    // cout << endl;
    //     for(int a = 1; a <= ilosc; a++){
    //         for(int b = 1; b <= dop; b++){
    //             cout << tab[a][b].wartosc << " ";
    //         }
    //         cout << endl;
    //     }

    //         cout << endl;
    //     for(int a = 1; a <= ilosc; a++){
    //         for(int b = 1; b <= dop; b++){
    //             cout << tab[a][b].ost << " ";
    //         }
    //         cout << endl;
    //     }


        cout << tab[ilosc][dop].wartosc << endl;

    int ilosci[25] {};

    int i = dop;
    while(i > 0 && przedmioty[tab[ilosc][i].ost].waga > 0){
        ilosci[tab[ilosc][i].ost]++;
        i -= przedmioty[tab[ilosc][i].ost].waga;
    }

    for(int i = 1; i <= ilosc; i++){
        if(ilosci[i] > 0){
            cout << i << " " << ilosci[i] << endl;
        }
    }
    
    return 0;
}