#include <iostream>
#include <vector>
/* #include <bitset> */

using namespace std;

typedef long long int ll;

const int MOD = 1e9+7;
const int MX = 21;

vector<int> adj[MX];
int dp[1<<MX][MX];

int n, m;
int solve(int mask, int a){
    /* cout << bitset<MX>(mask).to_string().substr(MX-n) << " " << a << endl; */
    if(dp[mask][a] > -1)
        return dp[mask][a];
    if(a == n){
        if(mask == (1<<n)-1)
            return 1;
        else
            return 0;
    }
    ll ret = 0;
    for(int b : adj[a]){
        int b_bit = 1 << (b-1);
        if(mask & b_bit)
            continue;
        /* cout << a << "-->" << b << endl; */
        int new_mask = mask | b_bit;
        ret += solve(new_mask, b);
        ret %= MOD;
    }
    dp[mask][a] = ret;
    return ret;
}

void zero(){
    for(int i = 0; i < 1<<MX; i++){
        for(int k = 0; k < MX; k++){
            dp[i][k] = -1;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    zero();
    cout << solve(1, 1);

    return 0;
}
