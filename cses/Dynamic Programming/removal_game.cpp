#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;

int memo[5007][5007];

int dp(int p, int q){
    if(p > q)
        return 0;
    if(memo[p][q] > 0){
        return memo[p][q];  
    }
    int ret = 0;
    ret  = max(ret, dp());
    memo[p][q] = ret;
    return ret;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    return 0;
}