#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

typedef long long int ll;

const int MX = 1e5+7;

vector<pair<int,int>> adj[MX];
priority_queue<ll> dist[MX];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0 ; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    dist[1].push(0);
    q.push({0,1});
    while(!q.empty()){
        ll d, a;
        tie(d, a) = q.top();
        q.pop();
        if(d > dist[a].top())
            continue;
        for(auto u : adj[a]){
            int b, w;
            tie(b, w) = u;
            if(dist[b].size() < k){
                dist[b].push(d+w);
                q.push({d+w, b});
            }
            else if(dist[b].top() > d+w){
                dist[b].pop();
                dist[b].push(d+w);
                q.push({d+w, b});
            }
        }
    }

    vector<ll> ans;
    while(!dist[n].empty()){
        ans.push_back(dist[n].top());
        dist[n].pop();
    }

    reverse(ans.begin(), ans.end());

    for(ll a : ans){
        cout << a << " ";
    }
    
    return 0;
} 