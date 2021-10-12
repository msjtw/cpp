#include <iostream>
#include <vector>

using namespace std;

struct rzecz{
    int waga;
    int wartosc;
};

struct kom{
    long long int wartosc;
    int ost;
};

vector <rzecz> przedmioty(107);
vector <int> zakazane;

int main(){
    int dop, ilosc;
    cin >> dop >> ilosc;

    for(int i = 0; i < ilosc; i++){
        cin >> przedmioty[i+1].waga >> przedmioty[i+1].wartosc;
    }

    kom tab[107][1007] {};
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

    int i = ilosc, j = dop;
    while(i > 0 &&  j > 0 && tab[i][j].wartosc > 0){
        if(tab[i][j].ost == 0){
            i--;
        }
        else{
            //cout << i << " ";
            zakazane.push_back(i);
            j -= przedmioty[i].waga;
            i--;
        }
    }
//cout << endl << endl;

    for(int i = 0; i < zakazane.size(); i++)
        przedmioty.erase(przedmioty.begin()+zakazane[i]);

    ilosc -= zakazane.size();

    kom tab2[107][1007] {};

    for(int i = 1; i <= przedmioty.size(); i++){
        for(int j = 0; j <= dop; j++){
            if(j-przedmioty[i].waga >= 0){
                if(tab2[i-1][j].wartosc > tab2[i-1][j-przedmioty[i].waga].wartosc+przedmioty[i].wartosc){
                    tab2[i][j].wartosc = tab2[i-1][j].wartosc;
                    tab2[i][j].ost = 0;

                }
                else{
                    tab2[i][j].wartosc = tab2[i-1][j-przedmioty[i].waga].wartosc+przedmioty[i].wartosc;
                    tab2[i][j].ost = 1;
                }
            }
            else{
                tab2[i][j].wartosc = tab2[i-1][j].wartosc;
                tab2[i][j].ost = 0;
            }
        }
    }

    long long int odp = 0;

    i = ilosc, j = dop;
    while(i > 0 &&  j > 0 && tab2[i][j].wartosc > 0){
        if(tab2[i][j].ost == 0){
            i--;
        }
        else{
            //cout << i << " ";
            j -= przedmioty[i].waga;
            odp += przedmioty[i].wartosc;
            i--;
        }
    }
//cout << endl << endl;
    cout << odp;

    return 0;
}