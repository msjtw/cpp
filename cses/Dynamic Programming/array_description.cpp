#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> arr;

const int MOD = 1000000007;
long long int memo[100007][107] {};

long long int dp(int a, int val){
    if(memo[a][val] != -1)
        return memo[a][val];

    long long int ret = 0;
    if(a == arr.size()-1){
        if(arr[a] == val or arr[a] == 0)
            ret = 1;
        else
            ret = 0;
    }
    else if(arr[a] > 0 and arr[a] != val){
            ret = 0;
    }
    else{
        if(val + 1 <= m)
            ret += dp(a+1, val + 1);
        ret %= MOD;
        ret += dp(a+1, val);
        ret %= MOD;
        if(val - 1 >= 1)
            ret += dp(a+1, val - 1);
        ret %= MOD;
    }
    memo[a][val] = ret;
    return ret;
}

int main(){
    for(int i = 0 ; i < 100007; i++){
        for(int  k = 0 ; k < 107; k++){
            memo[i][k] = -1;
        }
    }

    cin >> n >> m;
    for(int i = 0 ; i < n ;i ++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    if(arr[0] != 0){
        cout << dp(0, arr[0]);
    }
    else{
        long long int res = 0;
        for(int i = 1; i <= m; i++){
            res += dp(0, i);
            res %= MOD;
        }
        cout << res;
    }


    return 0;
}