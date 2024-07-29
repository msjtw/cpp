#include <iostream>
#include <vector>
#include <tuple>
#include <set>

using namespace std;

typedef long long int ll;

const int SIZE = 2507;

vector<tuple<int,int,int>> edges;
vector<int> adj[SIZE];
vector<int> rev_adj[SIZE];

set<int> nodes;
set<int> nodes2;

ll score[SIZE];
bool vis[SIZE];

int n, m;
bool poss = true;

int upd;

void dfs(int x){
    vis[x] = true;
    if(nodes.find(x) != nodes.end()){
        nodes2.insert(x);
    }
    for(int v : adj[x]){
        if(!vis[v])
            dfs(v);
    }
}

void dfs2(int x){
    vis[x] = true;
    if(nodes2.find(x) != nodes2.end())
        poss = false;
    for(int v : rev_adj[x]){
        if(!vis[v])
            dfs2(v);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b ,w;
        cin >> a >> b >> w;
        edges.push_back(tie(a,b,w));
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    for(int i = 0 ; i < SIZE; i++){
        score[i] = -__INT64_MAX__/2;
    }
    score[1] = 0;
    for(int i = 1; i <= n-1; i++){
        for(auto edge : edges){
            int a, b ,w;
            tie(a, b, w) = edge;
            score[b] = max(score[b], score[a]+w);
        }
    }

    for(auto edge : edges){
        int a, b ,w;
        tie(a, b, w) = edge;
        if(score[b] < score[a]+w)
            nodes.insert(b);
    }

    dfs(1);
    if(!nodes2.empty()){
        for(int i = 0 ; i < SIZE; i++){
            vis[i] = false;
        }
        dfs2(n);
    }

    if(poss){
        cout << score[n];
    }
    else{
        cout << -1;
    }

    return 0;
}