#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

typedef long long int ll;
typedef tuple<int ,int, int> project;

bool cmp(project l, project r){
    int la, lb, lr;
    tie(la, lb, lr) = l;
    int ra, rb, rr;
    tie(ra, rb, rr) = r;
    return lb < rb;
}

const int BASE = 1<<18;
ll tree[2*BASE] {};

void insert(int p, ll val){
    p += BASE;
    tree[p] = max(val, tree[p]);
    while(p > 0){
        p>>=1;
        tree[p] = max(tree[2*p], tree[2*p+1]);
    }
}

ll query(int p, int q){
    ll ret = 0;
    p += BASE -1;
    q += BASE +1;
    while(p>>1 != q>>1){
        if(not(p&1)){
            ret = max(ret, tree[p+1]);
        }
        if(q&1){
            ret = max(ret, tree[q-1]);
        }
        p>>=1;
        q>>=1;
    }
    return  ret;
}

int main(){
    int n;
    cin >> n;

    vector <project> pro;
    for(int i = 0; i < n; i++){
        int a, b ,c;
        cin >> a >> b >> c;
        pro.push_back({a, b, c});
    }
    sort(pro.begin(), pro.end(), cmp);

    int idx = 0;
    for(auto p : pro){
        int a, b, rew;
        tie(a, b, rew) = p;
        auto lb = lower_bound(pro.begin(), pro.end(), make_tuple(0, a, 0), cmp);
        lb--;
        ll prev = query(0, lb-pro.begin());
        insert(idx, prev+rew);
        idx++;
    }

    cout << tree[1];

    return 0;
}
