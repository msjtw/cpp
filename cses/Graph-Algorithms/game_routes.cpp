#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 1e5+7;
const int MOD = 1e9+7;

vector<int> adj[SIZE];
int memo[SIZE] {};

int n, m;

int ways(int a){
    if(memo[a] != -1){
        return memo[a];
    }
    int ret = 0;
    if(a == n){
        ret = 1;
    }
    else{
        for(int v : adj[a]){
            ret += ways(v);
            ret%=MOD;
        }
    }
    memo[a] = ret;
    return ret;
}

int main(){
    for(int i = 0 ; i < SIZE; i++){
        memo[i] = -1;
    }

    cin >> n >> m;
    for(int i = 0 ; i < m; i ++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    cout << ways(1);

    return 0;
}