#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

vector<pll> arr;

const int MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        ll a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    arr.push_back(arr[0]);

    long long int res = 0;

    for(int i = 0; i < n; i++){
        ll add = (arr[i].first*arr[i+1].second - arr[i+1].first*arr[i].second)%MOD;
        if(add < 0)
            add += MOD;
        res += add;
        res %= MOD;
    }

    cout << abs(res) << endl;

    return 0;
}