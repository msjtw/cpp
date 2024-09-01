#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

const int MX = 2e5+7;
const int BASE = 1<<18;

vector <int> adj[MX];
ll tree[BASE<<1];
int subtree[MX];
int flat[MX];
int vals[MX];

int idx = 1;
int dfs(int a, int p){
    flat[a] = idx;
    idx++;
    for(int b : adj[a]){
        if(b == p)
            continue;
        subtree[a] += dfs(b, a)+1;
    }
    return subtree[a];
}

void add(int a, int b, int v){
    a += BASE-1;
    b += BASE+1;
    while(a>>1 != b>>1){
        if(!(a&1))
            tree[a+1] += v;
        if(b&1)
            tree[b-1] += v;
        a >>= 1;
        b >>= 1;
    }
}

ll query(int a){
    ll ret = 0;
    a += BASE;
    while(a){
        ret += tree[a];
        a >>= 1;
    }
    return ret;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> vals[i];
    }
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++){
        int a = flat[i];
       add(a,a+subtree[i],vals[i]); 
    }

    /* for(int i = 1; i <= n; i++) */
    /*     cout << query(flat[i]) << " "; */

    while(q --> 0){
        int op, a, b;
        cin >> op;
        if(op == 1){
            cin >> a >> b;
            ll c = b-vals[a];
            vals[a] += c;
            add(flat[a],flat[a]+subtree[a],c);
        }
        else{
            cin >> a;
            cout << query(flat[a]) << endl;
        }
    }

    return 0;
}
