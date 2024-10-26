#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MX = 5e5+7;

vector<int> adj[MX];
vector<int> adjD[MX];

bool vis[MX];
bool in_q[MX];

vector<int> ord;


void zero(){
    for(int i = 0; i < MX; i++){
        vis[i] = false;
    }
}

void dfs1(int a){
    if(vis[a])
        return;
    vis[a] = true;
    for(int b : adj[a]){
        dfs1(b);
    }
}

void dfs2(int a){
    if(vis[a]){
        return;
    }
    vis[a] = true;
    for(int b : adjD[a]){
        dfs2(b);
    }
    ord.push_back(a);
}

int main (int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    zero();
    dfs1(1);
    if(!vis[2]){
        cout << "NIE";
        return 0;
    }
    for(int i = 3; i <= n; i++){
        if(!vis[i]){
            if(adj[i].size() > 0 ){
                cout << "NIE";
                return 0;
            }
            else{
                adj[1].push_back(i);
                adj[2].push_back(i);
                adj[i].push_back(1);
                adj[i].push_back(2);
            }
        }
    }

    int deg[MX] {};
    zero();
    int all =0;

    queue <int> q;
    q.push(1);
    in_q[1] = true;
    while(!q.empty()){
        all++;
        int a = q.front();
        q.pop();
        in_q[a] = false;
        vis[a] = true;
        for(int b : adj[a]){
            if(in_q[b]){
                cout << "NIE";
                return 0;
            }
            if(!vis[b]){
                deg[b]++;
                adjD[a].push_back(b);
            }
            if(deg[b] == adj[b].size()/2 and !vis[b] and b != 2){
                q.push(b);
                in_q[b] = true;
            }
        }
    }

    if(all != n-1){
        cout << "NIE";
        return 0;
    }

    zero();
    dfs2(1);

    int res[MX] {};

    cout << "TAK" << endl;
    int num = 1;
    for(int a : ord){
        res[a] = num;
        num++;
    }

    for(int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }

    return 0;
}
