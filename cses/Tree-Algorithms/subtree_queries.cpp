#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

const int MX = 2e5+7;
const int BASE = 1<<18;

vector<int> adj[MX];
ll tree[2*BASE];
int vals[MX];
int flat[MX];
int subtree[MX];
int idx = 0;

int dfs(int a, int p){
    flat[a] = idx;
    idx ++;
    for(int b : adj[a]){
        if(b == p)
            continue;
        subtree[a] += dfs(b, a)+1;
    }
    return subtree[a];
}

void insert(int x, int p){
    p += BASE;
    tree[p] = x;
    while(p){
        p >>= 1;
        tree[p] = tree[2*p] + tree[2*p+1];
    }
}

ll query(int a, int b){
    a += BASE-1;
    b += BASE+1;
    ll ret = 0;
    while(a>>1 != b>>1){
        if(!(a&1))
            ret += tree[a+1];
        if(b&1)
            ret += tree[b-1];
        a >>= 1;
        b >>= 1;
    }
    return ret;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> vals[i+1];
    }
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // cout << "yo" << endl;
    dfs(1, 0);
    // cout << "mr. white" << endl;
    for(int i = 0 ; i < n; i++){
        insert(vals[i+1], flat[i+1]);
    }
    // cout << "jessie?" << endl;
    // for(int i = 0 ; i <= n; i++){
    //     cout << subtree[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0 ; i <= n; i++){
    //     cout << flat[i] << " ";
    // }
    // cout << endl;
    while(q --> 0){
        int op, a, b;
        cin >> op;
        if(op == 1){
            cin >> a >> b;
            insert(b, flat[a]);
        }
        else{
            cin >> a;
            cout << query(flat[a], flat[a]+subtree[a]) << endl;
        }
    }

    return 0;
}
