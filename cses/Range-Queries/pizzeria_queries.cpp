#include <iostream>
#include <climits>

using namespace std;

const int BASE = 1<<18;

int uptree[2*BASE];
int downtree[2*BASE];

void insert(int tree[], int val, int p){
    p += BASE;
    tree[p] = val;
    while(p){
        p >>= 1;
        tree[p] = min(tree[2*p], tree[2*p+1]);
    }
}

int query(int tree[], int a, int b){
    a += BASE-1;
    b += BASE+1;
    int ret = INT_MAX;
    while(a>>1 != b>>1){
        if(!(a&1))
            ret = min(ret, tree[a+1]);
        if(b&1)
            ret = min(ret, tree[b-1]);
        a >>= 1;
        b >>= 1;
    }
    return ret;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        insert(uptree, a+i, i);
        insert(downtree, a+n-i+1, i);
    }
    // for(int i = BASE; i <= BASE+n; i++)
    //     cout << uptree[i] << " ";
    // cout << endl;
    while(q --> 0){
        int op, a, b;
        cin >> op;
        if(op == 1){
            cin >> a >> b;
            insert(uptree, b+a, a);
            insert(downtree, b+n-a+1, a);
        }
        else{
            cin >> a;
            int r1 = query(downtree, 1, a-1)-n+a-1;
            int r2 = query(uptree, a, n)-a;
            cout << min(r1, r2) << endl;;
        }
    }
    return 0;
}
