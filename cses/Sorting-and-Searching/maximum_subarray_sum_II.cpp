#include<iostream>
#include<vector>
#include<set>

using namespace std;

typedef long long int ll;

const int MX = 2e5;

ll pref[MX];

multiset <ll> vals;

int main(){
    int n, mini, maxi;
    cin >> n >> mini >> maxi;
    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        pref[i+1] = pref[i] + a;
    }

    long long int res = -__INT64_MAX__;

    int p = 0, q = 0;

    for(int i = mini; i <= n; i++){
        if(vals.size() <= maxi-mini){
            vals.insert(pref[q]);
            q++;
        }
        else{
            vals.erase(vals.find(pref[p]));
            p++;
            vals.insert(pref[q]);
            q++;
        }
        res= max(res, (pref[i]-*vals.begin()));
    }

    cout << res;

    return 0;
}