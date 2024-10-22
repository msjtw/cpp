#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

typedef long long int ll;
typedef tuple<int, int, int> tiii;

const int MX = 1e5+7;
const int BASE = 1<<17;

vector<tiii> adj[MX];
multiset<int> tree[BASE<<1];
int flat[MX];
int subtree[MX]; // subtree size
int vals[MX];
int roads_to_nodes[MX];

int idx = 1;
int dfs(int a, int p){
    flat[a] = idx;
    idx ++;
    for(tiii nxt : adj[a]){
        int b, w, r_num;
        tie(b, w, r_num) = nxt;
        if(b == p)
continue;
        vals[b] = w;
        roads_to_nodes[r_num] = b;
        subtree[a] += dfs(b, a)+1;
    }
    return subtree[a];
}

void add(int a, int b, int v){
    a += BASE-1;
    b += BASE+1;
    while(a >> 1 != b >> 1){
        if(!(a&1)){
            tree[a+1].insert(v);
        }
        if(b&1){
            tree[b+1].insert(v);
        }
        a >>= 1;
        b >>= 1;
    }
}

void remove(int a, int b, int v){
    a += BASE-1;
    b += BASE+1;
    while(a >> 1 != b >> 1){
        if(!(a&1)){
            tree[a+1].erase(v);
        }
        if(b&1){
            tree[b+1].erase(v);
        }
        a >>= 1;
        b >>= 1;
    }
}

int query(int a){
    set<int>    
}

int main (int argc, char *argv[]) {
    int n, m, z;
    cin >> n >> m >> z;
    for(int i = 0; i < n-1; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w, i+1});
        adj[b].push_back({a, w, i+1});
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++){
        int a = flat[i];
        add(a,a+subtree[i],vals[i]);
    }

    return 0;
}
