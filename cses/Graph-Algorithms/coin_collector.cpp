#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

typedef long long int ll;

const int MX = 1e5+7;

vector<int> adj[MX];
vector<int> tadj[MX];
stack<int> scc_stack;
set<int> scc_adj[MX];
set<int> scc_tadj[MX];

bool vis[MX];
int scc[MX];
int coins[MX];
ll scc_sum[MX];
ll res[MX];

vector<int> topo;

void dfs1(int a){
    vis[a] = true;
    for(int b : adj[a]){
        if(!vis[b])
            dfs1(b);
    }
    scc_stack.push(a);
}

void dfs2(int a, int scc_n){
    vis[a] = true;
    for(int b : tadj[a]){
        if(!vis[b])
            dfs2(b, scc_n);
    }
    scc[a] = scc_n;
}

void dfs3(int a){
    vis[a] = true;
    for(int b : scc_adj[a])
        if(!vis[b])
            dfs3(b);
    topo.push_back(a);
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> coins[i];
    for(int i = 0; i < m; i++){
        int a, b;
        cin  >> a >> b;
        adj[a].push_back(b);
        tadj[b].push_back(a);
    }
    for(int i = 1 ; i <= n; i++){
        if(!vis[i])
            dfs1(i);
    }

    for(int i = 0 ; i < MX; i++)
        vis[i] = false;

    int scc_n = 1;
    while(!scc_stack.empty()){
        int a = scc_stack.top();
        scc_stack.pop();
        if(scc[a] != 0)
            continue;
        dfs2(a, scc_n);
        scc_n++;
    }

    for(int i = 1; i <= n; i++){
        scc_sum[scc[i]] += coins[i];
    }

    for(int a = 1; a <= n; a++){
        for(int b : adj[a]){
            scc_adj[scc[a]].insert(scc[b]);
            scc_tadj[scc[b]].insert(scc[a]);
        }
    }

    for(int i = 0 ; i < MX; i++)
        vis[i] = false;

    for(int i = 1; i < scc_n; i++){
        if(!vis[i])
            dfs3(i);
    }

    reverse(topo.begin(), topo.end());

    ll maxi = 0;

    for(int a : topo){
        res[a] = scc_sum[a];
        for(int b : scc_tadj[a]){
            if(a == b)
                continue;
            res[a] = max(res[a], scc_sum[a] + res[b]);
        }
        maxi = max(maxi, res[a]);
    }

    cout << maxi;

    return 0;
}
