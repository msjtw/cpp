#include<iostream>
#include<map>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<queue>
#include<algorithm>

using namespace std;

bool cmp(pair<pair<string,string>,int> l, pair<pair<string,string>,int> r){
    return l.second > r.second;
}

map<string,vector<string>> adj;
vector<string> nodes;

map<pair<string,string>,int> num;
vector<pair<pair<string,string>,int>> edges;

void pth(string a, string b){
    map<string, string> path;
    for(auto node : nodes){
        path[node] = "";
    }

    queue<string> q;
    q.push(a);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(string v : adj[u]){
            if(path[v] == ""){
                path[v] = u;
                q.push(v);
            }
        }
    }
    while(b != a){
        num[{b,path[b]}]++;
        num[{path[b], b}]++;
        b = path[b];
    }
}

int bfs(string a){
    map<string, int> vis;
    for(auto node : nodes){
        vis[node] = 0;
    }

    int ret = 1;

    queue<string> q;
    vis[a] = 1;
    q.push(a);
    while(!q.empty()){
        string u = q.front();
        q.pop();
        for(string v : adj[u]){
            if(vis[v] == 0){
                ret++;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return ret;
}

int main(){
    srand(time(NULL));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        nodes.push_back(a);
        int m ;
        cin >> m;
        while(m --> 0){
            string b;
            cin >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    for(int ii = 0; ii < 1000; ii++){
        string a = nodes[(rand()%n)];
        string b = nodes[(rand()%n)];
        pth(a,b);
    }

    for(auto key : num){
        edges.push_back(key);
    }

    sort(edges.begin(), edges.end(), cmp);

    string a, b;

    for(int i = 0; i < 6; i++){
        auto edge  = edges[i];
        a = edge.first.first;
        b = edge.first.second;
        adj[a].erase(find(adj[a].begin(), adj[a].end(), b));
        adj[b].erase(find(adj[b].begin(), adj[b].end(), a));
        cout << edge.second << ": " << a << " " << b << endl;
    }

    cout << bfs(a) << bfs(b) << endl;
    cout << bfs(a)*bfs(b) << endl;

    return 0;
}
