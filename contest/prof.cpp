#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int,int> pii;
typedef long long int ll;

const int MX = 1007;

vector<pii> adj[MX];

ll dist[MX];
bool proc[MX];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    for(int i = 0; i <= n; i++){
        dist[i] = __INT64_MAX__;
        proc[i] = false;
    }
    dist[1] = 0;
    priority_queue<pii> q;
    q.push({0, 1});
    while(!q.empty()){
        int a = q.top().second; q.pop();
        if (proc[a]) continue;
        proc[a] = true;
        for (auto u : adj[a]) {
            ll b = u.first, w = u.second;
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }

    for(int i = 2; i <= n; i++){
        cout << (dist[i] == __INT64_MAX__ ? -1 : dist[i]) << " ";
    }

    return 0;
}