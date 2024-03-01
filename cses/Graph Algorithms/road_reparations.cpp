#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find(int);
bool same(int ,int);
void unite(int, int);

const int SIZE = 1e5+7;

vector<tuple<int,int,int>> edges;
vector<int> adj[SIZE];

int link[SIZE];
int s_size[SIZE];
int vis[SIZE];

long long int res = 0;

bool com(tuple<int,int,int> l, tuple<int,int,int> r){
    return get<2>(l) < get<2>(r);
}

int find(int x){
    while(x != link[x])
        x = link[x];
    return x;
}

bool same(int a, int b){
    return find(a) == find(b);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(s_size[a] < s_size[b])
        swap(a, b);
    s_size[a] += s_size[b];
    link[b] = a;
}

int dfs(int a){
    vis[a] = true;
    int ret = 1;
    for(int v : adj[a]){
        if(!vis[v]){
            ret += dfs(v);
        }
    }
    return ret;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < m; i++){
        int a, b ,w;
        cin >> a >> b >> w;
        edges.push_back(tie(a, b, w));
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    if(dfs(1) != n){
        cout << "IMPOSSIBLE";
        return 0;
    }

    sort(edges.begin(), edges.end(), com);
    
    for(int i = 1; i <= n; i++){
        link[i] = i;
        s_size[i] = 1;
    }

    for(auto edge : edges){
        int a, b, w;
        tie(a, b ,w) = edge;
        if(!same(a,b)){
            res += w;
            unite(a, b);
        }
    }

    cout << res;

    return 0;
}