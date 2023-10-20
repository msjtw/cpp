#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m;
stack <int> res;
vector<int> g[100007];
int vis[100007];
bool imp = false;

void dfs(int n){
    vis[n] = 1;
    for(int v : g[n]){
        if(vis[v] == 0)
            dfs(v);
        else if(vis[v] == 1)
            imp = true;
    }
    vis[n] = 2;
    res.push(n);
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i);
        }
    }

    if(!imp){
        while(!res.empty()){
            cout << res.top() << " ";
            res.pop();
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }

    return 0;
}