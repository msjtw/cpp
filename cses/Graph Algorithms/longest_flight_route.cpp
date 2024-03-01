#include<iostream>
#include<vector>

using namespace std;

const int SIZE = 1e5+7;

int n, m;

vector<int> adj[SIZE];
int memo[SIZE];
int path[SIZE];

int dfs(int a){
    if(memo[a] != -2){
        return memo[a];
    }
    int ret= -__INT_MAX__;
    if(a == n){
        ret = 1;
    }
    else{
        for(int v : adj[a]){
            int b = dfs(v)+1;
            if(b > ret){
                ret = b;
                path[a] = v;
            }
        }
    }

    memo[a] = ret;
    return ret;
}

int main(){
    for(int i = 0; i < SIZE; i++){
        memo[i] = -2;
    }

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int res = dfs(1);
    if(res <= 0){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << res << '\n';
        int a = 1;
        cout << 1 << " ";
        while(a != n){
            cout << path[a] << " ";
            a = path[a];
        }
    }

    return 0;
}