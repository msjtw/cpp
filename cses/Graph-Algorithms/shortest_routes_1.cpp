#include <iostream>
#include <queue>

using namespace std;

struct path{
    int w;
    int b;
};

const int SIZE = 1e5+7;

vector<pair<int,int>> adj[SIZE];
bool vis[SIZE] {};
long long int dist[SIZE] {};

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
    }

    for(int i = 0; i < SIZE; i++){
        dist[i] = __INT64_MAX__;
    }

    priority_queue<pair<long long int ,int>> q;
    dist[1] = 0;
    q.push({0, 1});
    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        if(vis[a]) continue;
        vis[a] = true;
        for(auto v : adj[a]){
            int b = v.first;
            int w = v.second;
            if(dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }

    return 0;
}