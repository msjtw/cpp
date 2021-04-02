//Stanislaw Fiedler VIII LO Poznan

#include <iostream>

using namespace std;

bool plansza[1005][1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int rows, cols, p;
    cin >> rows >> cols >> p;
    while(p--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int zmian = 0;
        bool zmiana[1010] {};

        for(int row = rows; row > 0; --row){
            bool w_lini = false;
            for(int col = cols; col > 0; --col){
                if(row >= a && row <= c && col >= b && col <= d)
                    plansza[row][col] = !plansza[row][col];
                bool stan = plansza[row][col];
                if(w_lini)
                    zmiana[col] = !zmiana[col];
                if(zmiana[col])
                    stan = !stan;
                if(stan){
                    zmian++;
                    zmiana[col] = !zmiana[col];
                    w_lini = !w_lini;
                }
            }
        }
        cout << zmian << "\n";


    }

    return 0;
}