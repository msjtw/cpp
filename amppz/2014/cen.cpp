#include <ios>
#include <iostream>
#include <vector>
#include <climits>
#include <bitset>

using namespace std;

vector<int>prices[107];
int dist[107];

int n, m;
int memo[1<<16];

int sum(int mask, int shop){
    int ret = 0;
    int i = 0;
    while(mask > 0){
        if(mask&1)
            ret += prices[shop][i];
        i++;
        mask >>= 1;
    }
    return ret;
}

int cost(int things){
    if (memo[things] >= 0) {
        return memo[things];
    }
    if(things == 0)
        return 0;
    // cout << bitset<5>(things).to_string() << endl;
    int mini = INT_MAX;
    int sub = things;
    while(sub > 0){
        // cout << '\t'  << bitset<5>(sub).to_string() << " " << bitset<5>(things-sub).to_string() << endl;
        for(int i = 1; i <= n; i++){
            mini = min(mini, dist[i]+sum(sub,i)+cost(things-sub));
        }
        sub = (sub-1)&things;
    }
    cout  << bitset<5>(things).to_string() << "  mini: " << mini << endl;
    memo[things] = mini;
    return mini;
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 1<<16; i++){
        memo[i] = -1;
    }
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> dist[i];
        for(int k = 0; k < m; k++){
            int a;
            cin >> a;
            prices[i].push_back(a);
        }
    }
    cout << cost((1<<m)-1);
    return 0;
}
