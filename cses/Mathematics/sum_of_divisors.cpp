#include<iostream>
#include<cmath>

using namespace std;

typedef long long int ll;

const int MOD = 1e9+7;

ll res= 0;

int main(){
    ll n;
    cin >> n;
    for(ll i = 1; i*i <= n; i++){
        ll count = n/i;
        ll add1 = ((count-i+1) * i)%MOD;
        ll add2 = ((count+i+1)%MOD)*((count-i)%MOD)/2;

        res = (res + add1)%MOD;
        res = (res + add2)%MOD;
    }

    cout << res;

    return 0;
}
