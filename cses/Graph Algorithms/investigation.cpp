#include<iostream>
#include<queue>
#include<vector>
#include<tuple>

using namespace std;

typedef long long int ll;

const int MX = 1e5+7;
const int MOD = 1e9+7;

vector<pair<int,int>> adj[MX];
int vis[MX];
int ways[MX];
ll dist[MX];
int min_v[MX];
int max_v[MX];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b ,w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    for(int i = 0 ; i < MX; i++){
        dist[i] = __INT64_MAX__;
    }
    priority_queue<pair<ll, int>> q;
    dist[1] = 0;
    ways[1] = 1;
    q.push({0,1});
    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        if(vis[a])
            continue;
        vis[a] = true;
        for(auto u : adj[a]){
        int b, w;
            tie(b, w) = u;
            if(dist[a]+w < dist[b]){
                dist[b] = dist[a]+w;
                ways[b] = ways[a];
                min_v[b] = min_v[a]+1;
                max_v[b] = max_v[a]+1;
                q.push({-dist[b], b});
            }
            else if(dist[a]+w == dist[b]){
                ways[b] = (ways[b] + ways[a])%MOD;
                min_v[b] = min(min_v[b], min_v[a]+1);
                max_v[b] = max(max_v[b], max_v[a]+1);
                q.push({-dist[b], b});
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " " << min_v[n] << " " << max_v[n];

    return 0;
}