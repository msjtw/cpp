#include<iostream>
#include<vector>

using namespace std;

const int MX = 2e5+7;

vector<int> adj[MX];
int path1[MX];
int path2[MX];
int c[MX];

void dfs1(int a, int p){
    path1[a] = 0;
    path2[a] = 0;
    for(int b : adj[a]){
        if(b == p)
            continue;
        dfs1(b, a);
        if(path1[b] + 1 > path1[a]){
            c[a] = b;
            path2[a] = path1[a];
            path1[a] = path1[b] + 1;
        }
        else if(path1[b] + 1 > path2[a]){
            path2[a] = path1[b] +1;
        }
    }
}

void dfs2(int a, int p){
    for(int b : adj[a]){
        if(b == p)
            continue;
        if(c[a] == b){
            if(path1[b] < path2[a]+1){
                path2[b] = path1[b];
                path1[b] = path2[a]+1;
                c[b] = a;
            }
            else{
                path2[b] = max(path2[b], path2[a]+1);
            }
        }
        else{
            c[b] = a;
            path2[b] = path1[b];
            path1[b] = path1[a] + 1;
        }
        dfs2(b ,a);
    }
}

int main(){
    int n, u, v;
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; i++){
        cout << path1[i] << " ";
    }
}
