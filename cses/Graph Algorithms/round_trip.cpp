#include<iostream>
#include<vector>

using namespace std;

const int SIZE = 1e5+7;

vector<int> adj[SIZE];
int vis[SIZE];

int start;

int dfs(int a, int len){
    vis[a] = true;
    if(a == start){
        return 0;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    return 0;
}