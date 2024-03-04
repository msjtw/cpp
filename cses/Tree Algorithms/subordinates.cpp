#include<iostream>
#include<vector>

using namespace std;

const int MX = 2e5+7;

vector<int> adj[MX];

int memo[MX];

void dfs(int a, int e){
    memo[a] = 1;
    for(int b : adj[a]){
        if(b != e){
            dfs(b, a);
            memo[a] += memo[b];
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int a;
        cin >> a;
        adj[a].push_back(i);
    }

    dfs(1, 1);

    for(int i = 1; i <= n; i++)
        cout << memo[i]-1 << " ";

    return 0;
}