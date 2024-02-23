#include <iostream>

using namespace std;

int memo[507][507];

int dp(int a, int b){
    if(memo[a][b] != -1){
        return memo[a][b];
    }
    int ret = 1e9+7;
    if(a == b){
        ret = 0;
    }
    else{
        for(int i = 1; a-i > 0; i++){
            ret = min(ret, dp(i,b)+dp(a-i,b)+1);
        }
        for(int i = 1; b-i > 0; i++){
            ret = min(ret, dp(a,i)+dp(a,b-i)+1);
        }
    }
    memo[a][b] = ret;
    return ret;
}

int main(){
    for(int i = 0; i < 507; i++){
        for(int k = 0; k < 507; k++){
            memo[i][k] = -1;
        }
    }

    int a, b;
    cin >> a >> b;
    cout << dp(a,b);
    return 0;
}