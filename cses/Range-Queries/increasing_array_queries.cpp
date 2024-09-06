#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pii;

struct queryS{
    ll a, b;
    ll idx;
};

const ll MX = 2e5+7;
const ll BASE = 1<<18;
const ll INF = INT_MAX;

vector<queryS> queires;
vector<pii> st;
ll arr[MX];
ll res[MX];
ll pref_sum[MX];
ll tree[2*BASE];

bool cmp(queryS l, queryS r){
    return l.a > r.a;
}

ll bfind(ll x){
    ll b = st.size()-1;
    for(ll k = st.size()/2; k > 0; k /=2){
        while(b-k >= 0 and st[b-k].first <= x)
            b -= k;
    }
    return b;
}

void insert(ll a, ll val){
    a += BASE;
    tree[a] = val;
    while(a){
        a >>= 1;
        tree[a] = tree[2*a] + tree[2*a+1];
    }
}

ll query(ll a, ll b){
    if(a > b)
        return 0;
    a += BASE-1;
    b += BASE+1;
    ll ret= 0;
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
    ll n, q;
    cin >> n >> q;
    for(ll i = 1; i <= n; i++){
        cin >> arr[i];
        pref_sum[i] = pref_sum[i-1]+arr[i];
    }
    for(ll i = 0 ; i < q; i++){
        queryS qr;
        cin >> qr.a >> qr.b;
        qr.idx = i;
        queires.push_back(qr);
    }

    sort(queires.begin(), queires.end(), cmp);

    ll idx = n;
    // index; value
    st.push_back({n+1,INF});
    for(auto qr : queires){
        ll a = qr.a;
        ll b = qr.b;
        ll qid = qr.idx;
        while(idx > 0){
            while((st.end()-1)->second <= arr[idx]){
                st.pop_back();
            }
            insert(st.size(), arr[idx]*(st[st.size()-1].first-idx));
            st.push_back({idx,arr[idx]});
            if(idx == a){
                ll b2 = bfind(b);
                ll rest = ll(b-st[b2].first+1)*(ll)st[b2].second;
                b2++;
                ll sum = query(b2,st.size()-1);
                sum += rest;
                ll org = pref_sum[b]-pref_sum[a-1];
                res[qid] = sum-org;
                break;
            }
            idx--;
        }
    }
    for(int i = 0 ; i < q; i ++){
        cout << res[i] << endl;
    }
    return 0;
}
