#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

const int MX = 2e5+7;

vector<int>adj[MX];

ll n, vv, ww;
ll sub_dist[MX] {};
ll sub_count[MX] {};
ll dist[MX] {};

ll iter = 0;
void dfs1(int a, int p){
    //cout << iter++ << ":  " << a << endl;
    for(int b : adj[a]){
        if(b == p)
            continue;
        dfs1(b, a);
        sub_count[a] += sub_count[b] + 1;
        sub_dist[a] += sub_dist[b] + sub_count[b] + 1;
    }
}

void dfs2(int a, int p){
    for(int b : adj[a]){
        if(b == p)
            continue;
        ll tcount = n - sub_count[b] - 1;
        if(tcount < 0)
            cout << "erroe 1" << endl;
        ll tdist = dist[a] - sub_dist[b] - sub_count[b] -1;
        if(tdist < 0)
            cout << "error 2" << endl;
        dist[b] = sub_dist[b] + tdist + tcount;
        dfs2(b, a);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){   
        cin >> vv >> ww;
        adj[vv].push_back(ww);
        adj[ww].push_back(vv);
    }
    dfs1(1,0);
    dist[1] = sub_dist[1];
    dfs2(1,0);
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    return 0;
}
