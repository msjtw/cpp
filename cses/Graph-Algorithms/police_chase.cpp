#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef long long int ll;

const int MX = 507;

ll flow[MX][MX];
ll used[MX][MX];

vector<int> adj[MX];
vector<int> radj[MX];

bool vis[MX];
bool bfs(int s, int lvl[], const int n){
    queue<int> q;
    q.push(1);
    lvl[1] = 1;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int v : adj[p]){
            if(lvl[v] == 0 and flow[p][v] - used[p][v] > 0){
                lvl[v] = lvl[p]+1;
                q.push(v);
            }
        }
        for(int v : radj[p]){
            if(lvl[v] == 0 and used[v][p] > 0){
                lvl[v] = lvl[p]+1;
                q.push(v);
            }
        }
    }
    return lvl[n] > 0;
}

int dfs(int x, ll val, const int lvl[], const int n){
    //cout << x << " ";
    vis[x] = true;
    if(x == n){
        return val;
    }
    for(int v : adj[x]){
        if(lvl[v] == lvl[x]+1 and flow[x][v] - used[x][v] > 0 and !vis[v]){
            int r = dfs(v, min(val, flow[x][v]-used[x][v]), lvl, n);
            if(r > 0){
                used[x][v] += r;
                return r;
            }
        }
    }
    for(int v : radj[x]){
        if(lvl[v] == lvl[x]+1 and used[v][x] > 0 and !vis[v]){
            int r = dfs(v, min(val, used[v][x]), lvl, n);
            if(r > 0){
                used[v][x] -= r;
                return r;
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < MX; i++){
        for(int k = 0; k < MX; k++){
            flow[i][k] = 0;
            used[i][k] = 0;
        }
    }
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        radj[b].push_back(a);
        radj[a].push_back(b);
        flow[a][b] += 1;
        flow[b][a] += 1;
    }

    int lvl[MX] {};

    long long int res = 0;

    while(bfs(1, lvl, n)){
        res += dfs(1, __INT_MAX__, lvl, n);
        for(int i = 0 ; i < MX; i++){
            vis[i] = false;
            lvl[i] = 0;
        }
    }
    cout << res << endl;
    for(int i = 0 ; i < MX; i++){
        vis[i] = false;
        lvl[i] = 0;
    }
 
    bfs(1, lvl, n);
    for(int a = 1; a <= n; a++){
        if(lvl[a] > 0){
            for(int b : adj[a]){
                if(lvl[b] == 0){
                    cout << a << " " << b << endl;
                }
            }
        }
    }
    return 0;
}
