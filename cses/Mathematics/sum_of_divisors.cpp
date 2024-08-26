#include<iostream>

using namespace std;

typedef long long int ll;

const int MOD = 1e9+7;

ll res= 0;

int main(){
    ll n;
    cin >> n;
    for(int i = 1; i*i <= n; i++){
        ll count = n/i;
        if()
        ll add = (count * i)%MOD;
        res = (res + add)%MOD;
    }
    cout << res;
    return 0;
}
