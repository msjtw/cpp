#include <iostream>

using namespace std;

typedef long long int ll;

const int MOD = 1e9+7;

int n, m; // n - collumns, m - rows 
int memo[11][1001] {};

void zero(){
    for(int a = 0; a < 11; a++){
        for(int b = 0; b < 1001; b++){
            memo[a][b] = -1;
        }
    }
}

bool next_mask(const int old, int &new){
    
}

int dp(int row, int mask){
    if(row == m)
        return 1;
    if(memo[row][mask] != -1)
        return memo[row][mask];
    int ret = 0;
    int new_mask
    while(next_mask(mask, new_mask)){
        ret += dp(row+1, new_mask);
        new_mask = 0;
    }
    memo[row][mask] = ret;
    return ret;
}

int main(){
    cin >> n >> m;
    cout << count(0, 0);
    return 0;
}
