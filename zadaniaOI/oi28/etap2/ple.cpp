#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef long long int ll;

const int MX = 5e5+7;
ll INF = (5e5*1e9)+7;

vector<int> vals;

int memo[2][MX] {};

ll solve(int sub, int n, ll s, ll l, ll r){
    if(s < l or s >= r or (sub == vals.size() and n != 0) or l > r){
        return INF;
    }
    if(n == 0){
        return s;
    }

    ll ret = INF;
    ret = min(ret, solve(sub+1, n-1, s+vals[sub], max(l, l+vals[sub]), r));
    ret = min(ret, solve(sub+1, n, s, l, min(r, l+vals[sub])));

    return ret;
}

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vals.push_back(a);
    }

    for(int i = n; i <= n; i++){
        cout << solve(0, i, 0, 0, INF) << " ";
    }

    for(int i = 1; i <= n; i++){
        for (init-statement; condition; inc-expression) {
        
        }
    }

    return 0;
}
