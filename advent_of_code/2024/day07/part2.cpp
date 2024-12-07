
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int ll;

vector<vector<ll>> tasks;
vector<ll> values;

ll comb(ll a, ll b){
    ll digits = to_string(b).length();
    ll res = a*pow(10,digits) + b;
    // cout << a << " " << b << " " << res << endl;
    return res;
}

int licznik = 0;
ll possible(ll i, ll sum, vector<ll> &nums, ll total){
    if(i == nums.size()){
        licznik++;
        if(sum == total)
            return total;
        else
            return 0;
    }
    ll v1 = possible(i+1, sum+nums[i], nums, total);
    ll v2 = possible(i+1, sum*nums[i], nums, total);
    ll v3 = possible(i+1, comb(sum, nums[i]), nums, total);
    return max(max(v1,v2), v3);
}

int main(){
    ll n;
    cin >> n;
    tasks.resize(n);
    for(ll i = 0; i < n;i ++){
        ll m, a;
        cin >> m;
        cin >> a;
        values.push_back(a);
        for(ll k = 0; k < m; k++){
            cin >> a;
            tasks[i].push_back(a);
        }
    }

    long long res = 0;

    for(ll i = 0; i < n; i++){
        cerr << i << ": ";
        licznik = 0;
        ll tmp = possible(1, tasks[i][0], tasks[i], values[i]);
        if(__INT64_MAX__  - tmp < res){
            cout << "error";
            return 0;
        }
        res += tmp;
        cout << licznik << endl;
    }

    cout << res;

    return 0;
}
