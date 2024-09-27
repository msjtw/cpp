#include<iostream>
#include<queue>
#include<set>

using namespace std;

typedef long long int ll;

const int MX = 1020;

ll flow[MX][MX];
ll used[MX][MX];

set<int> adj[MX];
set<int> Tadj[MX];

bool vis[MX];
int lvl[MX];

void zero(){
    for(int i = 0; i < MX; i++){
        vis[i] = false;
        lvl[i] = 0;
    }
}

bool bfs(int s, int n){
    queue<int> q;
    q.push(s);
    lvl[s] = 1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int b : adj[a]){
            if(lvl[b] == 0 and flow[a][b]-used[a][b] > 0){
                lvl[b] = lvl[a]+1;
                q.push(b);
            }
        }
        for(int b : Tadj[a]){
            if(lvl[b] == 0 and used[b][a] > 0){
                lvl[b] = lvl[a]+1;
                q.push(b);
            }
        }
    }
    return lvl[n] > 0;
}

ll dfs(int a, ll val, int n){
    vis[a] = true;
    if(a == n)
        return val;
    for(int b : adj[a]){
        if(lvl[b] == lvl[a]+1 and flow[a][b] - used[a][b] > 0 and !vis[b]){
            int r = dfs(b, min(val, flow[a][b]-used[a][b]), n);
            if(r > 0){
                used[a][b] += r;
                return r;
            }
        }
    }
    for(int b : Tadj[a]){
        if(lvl[b] == lvl[a]+1 and used[b][a] > 0 and !vis[b]){
            int r = dfs(b, min(val, used[b][a]), n);
            if(r > 0){
                used[b][a] -= r;
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

    int n, m, p;
    cin >> n >> m >> p;
    for(int i = 0; i < p; i++){
        int a, b;
        cin >> a >> b;
        b += n;
        adj[a].insert(b);
        Tadj[b].insert(a);
        flow[a][b] += 1;
    }

    int source = n+m+2;
    int sink = n+m+3;
    for(int i = 1; i <= n; i++){
        adj[source].insert(i);
        Tadj[i].insert(source);
        flow[source][i] = 1;
    }
    for(int i = n+1; i <= n+m; i++){
        adj[i].insert(sink);
        Tadj[sink].insert(i);
        flow[i][sink] = 1;
    }
    ll res = 0;
    zero();

    // for(int i = 0 ; i < MX; i++){
    //     if(adj[i].empty())
    //         continue;
    //     cout << i << ": ";
    //     for(int a : adj[i]){
    //         cout << a << " " ;
    //     }
    //     cout << endl;
    // }

    while(bfs(source, sink)){
        res += dfs(source, __INT64_MAX__, sink);
        zero();
    }

    cout << res << endl;

    zero();
    bfs(source, sink);

    for(int a = 1; a <= n; a++){
       for(int b : adj[a]){
            // cout << a << " " << b-n << " " << used[a][b] << endl;
            if(used[a][b] > 0){
                cout << a << " " << b-n << endl;
            }
        } 
    }


    return 0;
}
