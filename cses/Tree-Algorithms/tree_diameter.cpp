#include<iostream>
#include<vector>

using namespace std;

const int MX = 2e5+7;

vector<int> adj[MX];

int dist[MX];

int furth = 1;
int maxd;

void dfs(int a, int e){
    for(int b : adj[a]){
        if(b != e){
            dist[b] = dist[a]+1;
            if(dist[b] > maxd){
                maxd = dist[b];
                furth = b;
            }
            dfs(b, a);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(furth, 0);
    maxd = 0;
    for(int i = 0; i < MX; i++)
        dist[i] = 0;
    dfs(furth, 0);
    
    cout << maxd;

    return 0;
}