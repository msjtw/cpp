#include <iostream>

using namespace std;

typedef long long int ll;

const int BASE = 1<<18;
ll INF = __INT64_MAX__;

ll sum_tree[2*BASE];
ll pref_tree[2*BASE];

void pref_ins(int);

void sum_ins(int x, int pp){
    int p = pp + BASE;
    sum_tree[p] = x;
    p>>=1;
    while(p){
        sum_tree[p] = sum_tree[2*p] + sum_tree[2*p+1];
        p>>=1;
    }
    pref_ins(pp);
}

ll sum_query(int a, int b){
    a += BASE-1;
    b += BASE+1;
    ll res = 0;
    while(a >> 1 != b >> 1){
        if(!(a&1))
            res += sum_tree[a+1];
        if(b&1)
            res += sum_tree[b-1];
        a>>=1;
        b>>=1;
    }
    return res;
}

void pref_ins(int p){
    int a = sum_query(0, p);
    p += BASE;
    pref_tree[p] = a;
    p>>=1;
    while(p){
        pref_tree[p] = max(pref_tree[2*p], pref_tree[2*p+1]);
        p>>=1;
    }
}

ll pref_query(int a, int b){
    ll ret = -INF;
    a += BASE-1;
    b += BASE+1;
    while(a >> 1 != b >> 1){
        if(!(a&1))
            ret = max(ret, pref_tree[a+1]);
        if(b&1)
            ret = max(ret, pref_tree[b-1]);
        a >>= 1;
        b >>= 1;
    }
    return ret;
}

int main(){
    for(int i = 0 ; i < 2*BASE; i++)
        pref_tree[i] = -INF;

    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        sum_ins(a, i);
    }   
    for(int i = BASE; i < BASE +  n; i++)
        cout << pref_tree[i] << " ";

    while(q-->0){
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1){
            sum_ins(b, a-1);
        }
        else{
            cout << pref_query(a-1, b-1) << endl;
        }
    }

    return 0;
}
