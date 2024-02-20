#include<iostream>
#include<vector>

using namespace std;

typedef long long int ll;

vector <ll> machines;

ll parts(ll t){
    ll sum = 0;
    for(ll m : machines){
        sum += t/m;
    }
    return sum;
}

int main(){
    ll n, t;
    cin >> n >> t;
    ll mini = 1e10;
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        mini = min(mini, a);
        machines.push_back(a);
    }
    mini *= t;

    ll k = 0;
    for(ll b = mini/2; b >= 1; b/=2){
        while(k+b <= mini and parts(k+b) < t)
            k += b;
    }

    cout << k+1;

    return 0;
}