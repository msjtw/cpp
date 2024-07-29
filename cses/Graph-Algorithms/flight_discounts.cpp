#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

typedef long long int ll;

const int SIZE = 1e5+7;

vector<pair<int,int>> adj[SIZE];

ll dist[SIZE][2] {};
bool vis[SIZE][2] {};

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
    }
    
    for(int i = 0; i < SIZE; i++){
        dist[i][0] = __INT64_MAX__;
        dist[i][1] = __INT64_MAX__;
    }

    priority_queue<tuple<ll, int, int>> q;
    dist[1][0] = 0;
    q.push(make_tuple(0LL,1,0));
    while(!q.empty()){
        int d, u, a;
        tie(d, a, u) = q.top();
        q.pop();
        if(vis[a][u]) continue;
        vis[a][u] = true;
        for(auto v : adj[a]){
            int b = v.first;
            int w = v.second;
            if(dist[a][u] + w < dist[b][u]){
                dist[b][u] = dist[a][u] + w;
                q.push(make_tuple(-dist[b][u], b, u));
            }
            if(u == 0){
                if(dist[a][0] + w/2 < dist[b][1]){
                    dist[b][1] = dist[a][0] + w/2;
                    q.push(make_tuple(-dist[b][1], b, 1));
                }
            }
        }
    }

    cout << dist[n][1];

}