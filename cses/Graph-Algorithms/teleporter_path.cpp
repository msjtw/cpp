#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

const int MX = 1e5+7;

set<int> adj[MX];
set<int> tadj[MX];
int vis[MX];

int dfs(int a){
    vis[a] = true;
    int ret = 0;
    for(int b : adj[a]){
        if(!vis[b])
            ret += dfs(b) +1;
        else
            ret += 1;
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
        tadj[b].insert(a);
    }
    adj[n].insert(1);
    tadj[1].insert(n);
    
    if(dfs(1)-1 != m){
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(int i = 1; i <= n; i++){
        if(adj[i].size() != tadj[i].size()){
            cout << "IMPOSSIBLE";
            return 0;

        }
    }
    vector<int> ans;

    stack<int> s;
    s.push(1);
    while(!s.empty()){
        int a = s.top();
        if(adj[a].empty()){
            s.pop();
            ans.push_back(a);
        }
        else{
            int b = *adj[a].begin();
            adj[a].erase(adj[a].begin());
            s.push(b);
        }
    }

    reverse(ans.begin(), ans.end());

    if(ans[0] == 1 and ans[ans.size()-2] == n){
        for(int i = 0; i < ans.size()-1; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    else{
        int bor;
        bool ok = false;
        for(int i = 0 ; i < ans.size(); i++){
            if(ok)
                cout << ans[i] << " ";
            if(ans[i] == n and ans[i+1] == 1){
                ok = true;
                bor = i+1;
            }
        }
        for(int i = 1; i < bor; i++){
            cout << ans[i] << " ";
        }
    }
    return 0;
}
