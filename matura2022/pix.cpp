#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int pix[400][400];

int main(){

    int row, col;
    cin >> row >> col;

    for(int i = 0; i < row; i++){
        for(int k = 0; k < col; k++){
            cin >> pix[i][k];
        }
    }

    int maxi = 0;

    for(int i = 0; i < col; i++){
        int maxi2 = 0;
        int val = pix[0][col];
        int curr = 1;
        for(int k = 1; k < row; k++){
            if(pix[k][i] == val)
                curr++;
            else{
                maxi2 = max(maxi2, curr);
                val = pix[k][i];
                curr = 1;
            }
            maxi2 = max(maxi2, curr);
        }
        maxi = max(maxi, maxi2);
    }

    cout << maxi;
}