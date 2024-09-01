#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

const int MX = 2e5+7;
const int BASE = 1<<19;

vector<int> adj[MX];
int tree[BASE<<1];
int flat[MX][2];
int vals[MX];

int idx = 0;
void dfs(int a, int p){
    flat[a][0] = idx;
    idx++;
    bool leaf = true;
    for(int b : adj[a]){
        if(b == p)
            continue;
        leaf = false;
        dfs(b, a);
    }
    if(leaf){
        flat[a][1] = idx-1;
    }
    else{
        flat[a][1] = idx;
        idx++;
    }
}

void insert(int a, int v){
    a += BASE;
    tree[a] = v;
    while(a){
        a >>= 1;
        tree[a] = max(tree[2*a], tree[2*a+1]);
    }
}

int query(int a, int b){
    int ret = 0;
    a += BASE-1;
    b += BASE+1;
    while(a>>1 != b>>1){
        if(!(a&1))
            ret = max(ret, tree[a+1]);
        if(b&1)
            ret = max(ret, tree[b-1]);
        a >>= 1;
        b >>= 1;
    }
    return ret;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> vals[i];
    }
    for(int i = 0 ; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << "jessie?" << endl;
    dfs(1,0);
    cout << "yo" << endl;
    for(int i = 1; i <= n; i++){
        insert(flat[i][0], vals[i]);
        insert(flat[i][1], vals[i]);
    }
    cout << "mr. white?" << endl;
    while(q --> 0){
        int op, a ,b;
        cin >> op >> a >> b;
        if(op == 1){
            insert(flat[a][0], b);
            insert(flat[a][1], b);
        }
        else{
            a = flat[a][0];
            b = flat[b][1];
            if(a > b)
                swap(a, b);
            cout << query(a, b) << " ";
        }
    }
    return 0;
}
