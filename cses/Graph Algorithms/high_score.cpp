#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 2507;

vector<pair<int,int>> adj[SIZE];
int score[SIZE];
int vis[SIZE];

bool poss = true;

void dfs(int a){
    vis[a] = 1;
    for(auto v : adj[a]){
        int b, w;
        tie(b, w) = v;
        if(score[a] + w > score[b]){
            if(vis[b] == 0){

            }
            else if{
                pos 
            }
        } 
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b ,w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    dfs(1);

    if(poss){
        cout << score[n];
    }
    else{
        cout << -1;
    }

    return 0;
}