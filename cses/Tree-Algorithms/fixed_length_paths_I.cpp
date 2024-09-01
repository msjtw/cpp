#include <iostream>
#include <vector>

using namespace std;

const int MX = 2e5+7;

int n, k;
vector<int> adj[MX];
int subtree[MX];

int size_dfs(int a, int p){
    int ret = 1;
    for(int b : adj[a]){
        if(b == p)
            continue;
        ret += size_dfs(b, a);
    }
    return ret;
}

int cntr(int a, int p){
    for(int b : adj[a]){
        if(a == b)
            continue;
        if(subtree[b] > n/2)
            return cntr(b, a);
    }
    return a;
}

int paths(int a, int p){
    for(int i = 0; i < MX; i++)
        subtree[i] = 0;
    size_dfs(a, p);
    int c = cntr(a, p);
    int ret = 0;
    for(int b : adj[]){
    }
}

int main(){
    cin >> n >> k;
    for(int i =  1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    size_dfs(1, 0);
    int c = cntr(1, 0);
    
    return 0;
}
