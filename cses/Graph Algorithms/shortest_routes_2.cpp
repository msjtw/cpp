#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 507;

vector <pair<int,int>> adj[SIZE];
int n, m ,q;

int main(){
    cin >> n >> m >> q;
    for(int i = 0; i < m; i ++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    long long int dist[SIZE][SIZE] {};
    for(int i = 0; i <= n; i++){
        for(int k = 0; k <= n; k++){
            dist[i][k] = __INT64_MAX__/2;
        }
    }
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
        for(auto v : adj[i]){
            int b = v.first;
            long long int w = v.second;
            dist[i][b] = min(w, dist[i][b]);
            dist[b][i] = min(w, dist[i][b]);
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while(q --> 0){
        int a, b;
        cin >> a >> b;
        cout << (dist[a][b] == __INT64_MAX__ /2 ? -1 : dist[a][b]) << endl;
    }

    return 0;
}