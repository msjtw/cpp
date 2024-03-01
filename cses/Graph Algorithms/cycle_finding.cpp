// true spaghetti monster

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>

using namespace std;

typedef long long int ll;

const int INF = __INT_MAX__;
const int SIZE = 2507; 

vector<tuple<int,int,int>> edges;
int par[SIZE];

ll dist[SIZE];
bool vis[SIZE] {};

bool found = false;
int node = 0;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0 ;i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(tie(a,b,c));
    }

    for(int i = 0 ; i < SIZE; i++){
        dist[i] = INF;
    }

    dist[1] = 0;
    for(int i = 1; i <= n-1; i++){
        for(auto e : edges){
            int a, b, w;
            tie(a, b ,w) = e;
            if(dist[b] > dist[a]+w){
                par[b] = a;
                dist[b] = dist[a]+w;
            }
        }
    }
    for(auto e : edges){
        int a, b, w;
        tie(a, b ,w) = e;
        if(dist[b] > dist[a]+w){
            found = true;
            node = b;
            par[b] = a;
            dist[b] = dist[a]+w;
        }
    }
    
    if(found){
        cout << "YES\n";
        vector<int> res;
        set<int> vals;
        res.push_back(node);
        vals.insert(node);
        int b = par[node];
        while(node != b and vals.find(b) == vals.end()){
            res.push_back(b);
            vals.insert(b);
            b = par[b];
        }
        res.push_back(b);
        cout << res[res.size()-1] << " ";
        for(int i = res.size()-2; i >= 0 and res[i] != res[res.size()-1];i--){
            cout << res[i] << " ";
        }
        cout << res[res.size()-1];
    }
    else{
        cout << "NO";
    }

    return 0;
}