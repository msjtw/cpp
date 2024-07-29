#include<iostream>
#include<bitset>

using namespace std;

const int MOD = 1e9+7;

int memo[507][125257] {};

int dp(int n){
    double x = ((n+1)*n)/4.0;
    int sum = x;
    if(x != sum)
        return 0;
    
    for(int i = 0; i <= n; i++)
        memo[i][0] = 0;
    for(int i = 0; i <= sum; i++)
        memo[0][i] = 0;
    memo[0][0] = 1;

    for(int i = 1 ; i <= n; i++){
        for(int k = 1 ; k <= sum; k++){
            memo[i][k] = memo[i-1][k];
            if(k-i >= 0){
                memo[i][k] += memo[i-1][k-i];
            }
            memo[i][k] %= MOD;
        }
    }

    return memo[n][sum];
}

int main(){
    int n;
    cin >> n;

    cout << dp(n);

    return 0;
}