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
                if(tab[i-1][j].wartosc > tab[i-1][j-przedmioty[i].waga].wartosc+przedmioty[i].wartosc){
                    tab[i][j].wartosc = tab[i-1][j].wartosc;
                    tab[i][j].ost = 0;

                }
                else{
                    tab[i][j].wartosc = tab[i-1][j-przedmioty[i].waga].wartosc+przedmioty[i].wartosc;
                    tab[i][j].ost = 1;
                }
            }
            else{
                tab[i][j].wartosc = tab[i-1][j].wartosc;
                tab[i][j].ost = 0;
            }
            
        }
        
    }

    cout << endl;
        for(int a = 1; a <= ilosc; a++){
            for(int b = 1; b <= dop; b++){
                cout << tab[a][b].wartosc << " ";
            }
            cout << endl;
        }

            cout << endl;
        for(int a = 1; a <= ilosc; a++){
            for(int b = 1; b <= dop; b++){
                cout << tab[a][b].ost << " ";
            }
            cout << endl;
        }


    cout << tab[ilosc][dop].wartosc << endl;

    int i = ilosc, j = dop;
    while(i > 0 &&  j > 0 && tab[i][j].wartosc > 0){
        if(tab[i][j].ost == 0){
            i--;
        }
        else{
            cout << i << " ";
            j -= przedmioty[i].waga;
            i--;
        }
    }

    
    return 0;
}