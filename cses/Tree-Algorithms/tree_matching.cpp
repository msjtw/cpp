#include<iostream>
#include<vector>

using namespace std;

const int MX = 2e5+7;

vector<int> adj[MX];

int dp[MX][2];

void dfs(int a, int p){
    for(int b : adj[a]){
        if(b == p)
            continue;
        dfs(b, a);
        dp[a][0] += max(dp[b][0], dp[b][1]);
    }
    for(int b : adj[a]){
        if(b == p)
            continue;
        int tmp = dp[a][0] - max(dp[b][0], dp[b][1]) + dp[b][0];
        dp[a][1] = max(dp[a][1], tmp+1);
    }
}

int main(){
    for(int i = 0 ; i < MX; i++){
        dp[i][0] = 0;
        dp[i][1] = -MX;
    }

    int n, vv, ww;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> vv >> ww;
        adj[vv].push_back(ww);
        adj[ww].push_back(vv);
    }

    dfs(1,0);

    cout << max(dp[1][0], dp[1][1]);

    return 0;
}
