#include <ios>
#include <iostream>
#include <vector>

using namespace std;

const int MX = 2e5+7;
vector<int> adj[MX];
int subtree[MX];
int n;

int size_dfs(int a, int p){
    int ret= 1;
    for(int b : adj[a]){
        if(b == p)
            continue;
        ret += size_dfs(b, a);
    }
    subtree[a] = ret;
    return ret;
}

int find_cntr(int a, int p){
    for(int b : adj[a]){
        if(b == p)
            continue;
        int s = subtree[b];
        if(s > n/2){
            return find_cntr(b, a);
        }
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1 ; i < n;i ++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    size_dfs(1, 0);
    cout << find_cntr(1, 0);
    return 0;
}
