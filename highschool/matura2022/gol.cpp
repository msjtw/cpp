#include <iostream>

using namespace std;

int pl1 [100][100] {};
int pl2 [100][100] {};

int licz(int row, int col){
    return pl1[row-1][col-1] + pl1[row][col-1] + pl1[row+1][col-1] + pl1[row-1][col] + pl1[row+1][col] + pl1[row-1][col+1] + pl1[row][col+1] + pl1[row+1][col];
}

int main(){
    for(int i = 1; i <= 12; i++){
        for(int k = 1; k <= 20; k++){
            char c;
            cin >> c;
            if(c == '.')
                pl1[i][k] = 0;
            else    
                pl1[i][k] = 1;
        }
    }

    for(int i = 1; i <= 12; i++){
        pl1[i][21] = pl1[i][1];
        pl1[i][0] = pl1[i][20];
    }
    for(int i = 1; i <= 20; i++){
        pl1[13][i] = pl1[1][i];
        pl1[0][i] = pl1[12][i];
    }
    pl1[0][0] = pl1[12][20];
    pl1[13][0] = pl1[1][20];
    pl1[0][21] = pl1[12][1];
    pl1[13][21] = pl1[1][1];


    for(int i = 0; i <= 13; i++){
        for(int k = 0; k <= 21; k++){
            cout << pl1[i][k];
        }
        cout << endl;
    }
    cout << endl;

    int pokolenie = 36;
    while(pokolenie--){
        for(int i = 1; i <= 12; i++){
            for(int k = 1; k <= 20; k++){
                int som = licz(i,k);
                if((pl1[i][k] && (som == 2 || som == 3)) || (!pl1[i][k] && som == 3))
                    pl2[i][k] = 1;
                else
                    pl2[i][k] = 0;

            }
        }
        swap(pl1, pl2);
        for(int i = 1; i <= 12; i++){
            pl1[i][21] = pl1[i][1];
            pl1[i][0] = pl1[i][20];
        }
        for(int i = 1; i <= 20; i++){
            pl1[13][i] = pl1[1][i];
            pl1[0][i] = pl1[12][i];
        }
        pl1[0][0] = pl1[12][20];
        pl1[13][0] = pl1[1][20];
        pl1[0][21] = pl1[12][1];
        pl1[13][21] = pl1[1][1];

            for(int i = 0; i <= 13; i++){
        for(int k = 0; k <= 21; k++){
            cout << pl1[i][k];
        }
        cout << endl;
    }
    cout << endl;

    }

    cout << licz(2,19);

    return 0;
}