#include <iostream>

using namespace std;

const int SIZE = 1e6+7;

int memo[SIZE] {};

int dp(int n){
    if(memo[n] != 0)
        return memo[n];
    if(n == 0)
        return 0;
    int m = n;
    int res = __INT_MAX__;
    while(m){
        int d = m%10;
        m/=10;
        if(n-d >= 0 and d > 0)
            res = min(res, dp(n-d)+1);
    }
    memo[n] = res;
    return res;
}

int main(){
    int n;
    cin >> n;
    cout << dp(n);
    return 0;
}