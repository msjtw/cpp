#include <iostream>

using namespace std;

int dane[30][3];
int liczb;

int dp(int x, int y, int mini, int maxi){
    if(x = liczb-1)
        return(dane[x][y]);
    else 
        return(min(dp(x+1,0),min(dp(x+1,1), dp(x+1,2)))) + dane[x][y];
}

int main(){
    cin >> liczb;

    for(int i = 0; i < liczb; i++){
        cin >> dane[i][0] >> dane[i][1] >> dane[i][2];
    }

    cout << min(dp(0,0),min(dp(0,1), dp(0,2)));

    return 0;
}