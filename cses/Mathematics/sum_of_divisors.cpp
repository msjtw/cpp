#include<iostream>

using namespace std;

typedef long long int ll;

const int MOD = 1e9+7;

ll res= 0;

int main(){
    ll n;
    cin >> n;
    for(ll i = 1; i*i <= n; i++){
        if(n%i == 0){
            cout << i << " " << n/i << " ";
            res += i;
            res %= MOD;
            if(i*i != n)
                res += (n/i);
            res %= MOD;
        }
    }
    cout << res;
    return 0;
}