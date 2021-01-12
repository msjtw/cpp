#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct cell{
    int row;
    int col;
};

int rows, cols;
string line;

int plansza[200][200];

int main(){
    ios_base::sync_with_stdio(false);

    queue <cell> kol;

    cin >> rows >> cols;
    for(int i = 1; i <= rows; i++){
        cin >> line;
        for(int k = 1; k <= line.size(); k++){
            plansza[i][k] = -1;
            if(line[k-1] == '1'){
                kol.push({i, k});
                plansza[i][k] = 0;
            }
        }
    }

    while(kol.size() > 0){
        cell m = kol.front();
        kol.pop();
        if(plansza[m.row-1][m.col] == -1){
            plansza[m.row-1][m.col] = plansza[m.row][m.col] +1;
            kol.push({m.row-1,m.col});
        }
        if(plansza[m.row+1][m.col] == -1){
            plansza[m.row+1][m.col] = plansza[m.row][m.col] +1;
            kol.push({m.row+1,m.col});
        }
        if(plansza[m.row][m.col-1] == -1){
            plansza[m.row][m.col-1] = plansza[m.row][m.col] +1;
            kol.push({m.row,m.col-1});
        }
        if(plansza[m.row][m.col+1] == -1){
            plansza[m.row][m.col+1] = plansza[m.row][m.col] +1;
            kol.push({m.row,m.col+1});
        }
    }

    for(int i = 1; i <= rows; i++){
        for(int k = 1; k <= cols; k++){
            cout << plansza[i][k] << " ";
        }
        cout << endl;
    }

    return 0;
}