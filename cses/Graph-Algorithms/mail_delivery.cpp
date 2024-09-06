#include<iostream>
#include<set>
#include<stack>
#include<vector>

using namespace std;

const int MX = 1e5+7;

set <int> adj[MX];

bool vis[MX];

void zero(){
    for(int i = 0; i < MX; i++)
        vis[i] = false;
}

int dfs1(int a){
    int ret = 0;
    vis[a] = true;
    for(int b : adj[a]){
        ret += 1;
        if(!vis[b])
            ret += dfs1(b);
    }
    return ret;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    zero();
    if(dfs1(1)/2 != m){
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(int i = 1; i <= n; i++){
        if(adj[i].size() & 1){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    vector<int> ans;

    stack<int> s;
    s.push(1);
    while(!s.empty()){
        int a = s.top();
        if(adj[a].size() == 0){
            ans.push_back(a);
            s.pop();
        }
        else{
            int b = *adj[a].begin();
            adj[a].erase(adj[a].begin());
            adj[b].erase(a);
            s.push(b);
        }
    }

    for(int a : ans)
        cout << a << " ";


    return 0;
}
