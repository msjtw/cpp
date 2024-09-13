#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

const int MOD = 1e9+7;

ll pow(ll x, ll k){
    if(k == 0)
        return 1;
    if(k&1){
        return (pow(x,k-1)*x)%MOD;
    }
    else{
        ll tmp = pow(x, k/2);
        return (tmp*tmp)%MOD;
    }
}

vector<pll> fact;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        fact.push_back({a, b});
    }

    ll num = 1;
    for(pll fa : fact){
        num *= fa.second+1;
        num %= MOD;
    }

    ll sum = 1;
    for(pll fa : fact){
        ll p = (pow(fa.first,fa.second+1)-1)*pow((fa.first-1),MOD-2);
        p %= MOD;
        sum *= p;
        sum %= MOD;
    }

    ll prod = 1;
    ll tot = 1;
    for(pll fa : fact){
        prod = pow(prod, fa.second+1) * pow(pow(fa.first, (fa.second * (fa.second+1))/2), tot) % MOD;
        tot = tot*(fa.second+1)%(MOD-1);
    }
    cout << num << " " << sum << " " << prod << " ";

    return 0;
}
