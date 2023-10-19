#include <iostream>

using namespace std;

const int MOD = 1000000007;
int dp[1000007] {};

int ways(int n){
    if(n == 0)
        return 1;

    if(dp[n] != 0)
        return dp[n];

    int res = 0;
    for(int i = 1; i <= 6; i++){
        if(n-i >= 0){
            res += ways(n-i);
            res %= MOD;
        }
    }
    dp[n] = res;
    return res;
}

int main(){
    int n;
    cin >> n;
    cout << ways(n);
    return 0;
}