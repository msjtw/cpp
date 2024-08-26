#include<iostream>
#include<vector>

using namespace std;

const int MX = 2e5+7;
const int LOG_MX = 18;

vector<int> adj[MX];
int parent[MX][LOG_MX];
int level[MX];
int paths[MX][3];
int res[MX];

void level_dfs(int a, int p){
    for(int b : adj[a]){
        if(b == p)
            continue;
        parent[b][0] = a;
        level[b] = level[a]+1;
        level_dfs(b, a);
    }
}


void fill(){
    for(int i = 1; i < LOG_MX; i++){
        for(int k = 1; k < MX; k++){
            parent[k][i] = parent[parent[k][i-1]][i-1];
        }
    }
}

int up(int a, int k){
    int exp = 0;
    while(k){
        if(k&1){
            a = parent[a][exp];
        }
        exp++;
        k>>=1;
    }
    return a;
}

int path_dfs(int a, int p){
    int pth = 0;
    for(int b : adj[a]){
        if(b == p)
            continue;
        pth += path_dfs(b, a);
    }
    pth += paths[a][0];
    pth -= paths[a][2];
    res[a] = pth;
    return pth - paths[a][1];
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    level_dfs(1, 0);
    fill();
    while(m --> 0 ){
        int a, b;
        cin >> a >> b;
        paths[a][0]++;
        paths[b][0]++;
        //cout << "lvl: " << level[a] << " " << level[b] << endl;
        if(level[a] > level[b])
            swap(a, b);
        b = up(b, level[b]-level[a]);
        //cout << b << endl;
        if(a == b){
            //cout << m << " a " << a << endl;
            paths[a][0]--;
            paths[a][1]++;
            continue;
        }
        for(int x = LOG_MX-1; x >= 0; x--){
            while(parent[a][x] != parent[b][x]){
                a = parent[a][x];
                b = parent[b][x];
            }
        }
        int lca = parent[a][0];
        //cout << m << " b " << lca << endl;
        paths[lca][1]++;
        paths[lca][2]++;
    }
    path_dfs(1, 0);
    /* for(int i = 1; i <= n; i++){ */
    /*     cout << paths[i][0] << " "; */
    /* } */
    /* cout << endl; */
    /* for(int i = 1; i <= n; i++){ */
    /*     cout << paths[i][1] << " "; */
    /* } */
    /* cout << endl; */
    /* for(int i = 1; i <= n; i++){ */
    /*     cout << paths[i][2] << " "; */
    /* } */
    /* cout << endl; */
    for(int i = 1; i <= n; i++)
        cout << res[i] << " ";
    return 0;
}
