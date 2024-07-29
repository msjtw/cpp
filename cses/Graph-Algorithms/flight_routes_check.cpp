#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MX = 1e5+7;

vector<int> adj[MX];
vector<int> r_adj[MX];

bool vis[MX];
vector<int> proc;

int comp[MX];
int comp_num = 1;

int proc_time = 0;

void dfs(int a){
    proc_time++;
    vis[a] = true;
    for(int b : adj[a]){
        if(!vis[b])
            dfs(b);
    }
    proc_time++;
    proc.push_back(a);
}

void dfs2(int a){
    comp[a] = comp_num;
    for(int b : r_adj[a]){
        if(comp[b] == 0)
            dfs2(b);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        r_adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i])
            dfs(i);
    }

    reverse(proc.begin(), proc.end());

    vector<int> ans;

    for(int a : proc){
        if(comp[a] == 0){
            dfs2(a);
            comp_num++;
            ans.push_back(a);
        }
    }

    if(comp_num > 2){
        cout << "NO\n";
        cout << ans[1] << " " << ans[0];
    }
    else{
        cout << "YES";
    }

    return 0;
}