#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef long long int ll;

const int SIZE = 1e5+7;

vector<pair<int,int>> adj[SIZE];

pair<ll, int> dist[SIZE] {};
bool vis[SIZE] {};

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
    }
    
    for(int i = 0; i < SIZE; i++){
        dist[i] = {__INT64_MAX__, 0};
    }

    priority_queue<pair<ll, int>> q;
    dist[1] = {0, 0};
    q.push({0,1});
    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        //if(vis[a]) continue;
        vis[a] = true;
        for(auto v : adj[a]){
            int b = v.first;
            int w = v.second;
            if((dist[a].first + w - (max(dist[a].second, w) - max(dist[a].second, w)/2)) < (dist[b].first - dist[b].second/2)){
                dist[b] = {dist[a].first + w, max(dist[a].second, w)};
                q.push({-(dist[a].first + w - (max(dist[a].second, w) - max(dist[a].second, w)/2)) , b});
            }
        }
    }

    cout << dist[n].first - (dist[n].second - dist[n].second/2);

}