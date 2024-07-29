#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int SIZE = 1e5+7;

vector<int> adj[SIZE];
int vis[SIZE];

int found = 0;
bool ret = true;

vector<int> res;

void dfs(int a){
    vis[a] = 1;
    for(int v : adj[a]){
        if(found == 0){
            if(vis[v] == 1){
                res.push_back(v);
                found = v;
            }
            else if(vis[v] == 0){
                dfs(v);
            }
        }
    }
    if(ret and found > 0){
        res.push_back(a);
    }
    if(a == found){
        ret = false;
    }
    vis[a] = 2;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i);
        }
    }

    if(res.size() > 0){
        reverse(res.begin(),res.end());
        cout << res.size() << endl;
        for(auto a : res){
            cout << a << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }

    return 0;
}