#include <iostream>
#include <iostream>
#include <queue>

using namespace std;
const int maxN = 1e5+7;

int p[maxN], dist[maxN];
bool vis[maxN];
vector<int> net[maxN];
queue<int> Q;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        net[a].push_back(b);
        net[b].push_back(a);
    }

    Q.push(1);
    vis[1] = true;
    dist[1] = 1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int v : net[u]){
            if(!vis[v]){
                dist[v] = dist[u]+1;
                vis[v] = true;
                p[v] = u;
                Q.push(v);
            }
        }
    }

    if(!vis[n]){
        printf("IMPOSSIBLE\n");
    }
    else{
        cout << dist[n] << endl;
        vector<int> path;
        int k = n;
        while(k != 0){
            path.push_back(k);
            k = p[k];
        }
        for(int i = path.size()-1; i >= 0; i--)
            cout << path[i] << " ";
    }

    return 0;
}