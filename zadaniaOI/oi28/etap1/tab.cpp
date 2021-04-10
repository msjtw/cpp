//Stanislaw Fiedler VIII LO Poznan

#include <iostream>

using namespace std;

bool zmiany[1005][1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int rows, cols, p;
    int zmian = 0;
    cin >> rows >> cols >> p;
    while(p--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if(zmiany[y2][x2])
            zmian--;
        else
            zmian++;
        zmiany[y2][x2] ^= 1;

        if(x1 > 1){
            if(zmiany[y2][x1-1])
                zmian--;
            else
                zmian++;
            zmiany[y2][x1-1] ^= 1;
        }
        if(y1 > 1){
            if(zmiany[y1-1][x2])
                zmian--;
            else
                zmian++;
            zmiany[y1-1][x2] ^= 1;
        }
        if(x1 > 1 && y1 > 1){
            if(zmiany[y1-1][x1-1])
                zmian--;
            else
                zmian++;
            zmiany[y1-1][x1-1] ^= 1;
        }

        
        cout << zmian << "\n";


    }

    return 0;
}