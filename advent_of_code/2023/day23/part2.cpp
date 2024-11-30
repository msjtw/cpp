#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
#include<cstdint>

using namespace std;

pair<int,int> BEGIN = {1,1};
pair<int,int> END = {139,139};

int end_num = 0;
int next_node = 2;

string lab[150];
int node[150][150];
bool vis[150][150];
vector<pair<int,int>> adj[100];


void make_better(){
    int node_next = 2;
    queue<pair<pair<int,int>,int>> q;
    set<pair<int,int>> tmp_adj[10000];
    q.push({BEGIN,1});
    while(!q.empty()){
        auto curr = q.front().first;
        int a = q.front().second;
        q.pop();

        if(curr == END)
            end_num = a;
        
        pair<int,int> next;
        next = {curr.first-1, curr.second};
        if(node[next.first][next.second] != 0){
            tmp_adj[a].insert({node[next.first][next.second],1});
            tmp_adj[node[next.first][next.second]].insert({a,1});
        }
        next = {curr.first+1, curr.second};
        if(node[next.first][next.second] != 0){
            tmp_adj[a].insert({node[next.first][next.second],1});
            tmp_adj[node[next.first][next.second]].insert({a,1});
        }
        next = {curr.first, curr.second-1};
        if(node[next.first][next.second] != 0){
            tmp_adj[a].insert({node[next.first][next.second],1});
            tmp_adj[node[next.first][next.second]].insert({a,1});
        }
        next = {curr.first, curr.second+1};
        if(node[next.first][next.second] != 0){
            tmp_adj[a].insert({node[next.first][next.second],1});
            tmp_adj[node[next.first][next.second]].insert({a,1});
        }


        next = {curr.first-1, curr.second};
        if(!vis[next.first][next.second] and lab[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            node[next.first][next.second] = node_next;
            q.push({next, node_next});
            node_next++;
        }
        next = {curr.first+1, curr.second};
        if(!vis[next.first][next.second] and lab[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            node[next.first][next.second] = node_next;
            q.push({next, node_next});
            node_next++;
        }
        next = {curr.first, curr.second-1};
        if(!vis[next.first][next.second] and lab[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            node[next.first][next.second] = node_next;
            q.push({next, node_next});
            node_next++;
        }
        next = {curr.first, curr.second+1};
        if(!vis[next.first][next.second] and lab[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            node[next.first][next.second] = node_next;
            q.push({next, node_next});
            node_next++;
        }
    }

    for(int i = 1; i < node_next; i++){
        if(tmp_adj[i].size() == 2){
            auto pt = tmp_adj[i].begin();
            auto a = *pt;
            pt++;
            auto b = *pt;
            tmp_adj[a.first].erase({i, a.second});
            tmp_adj[b.first].erase({i, b.second});
            tmp_adj[a.first].insert({b.first, a.second+b.second});
            tmp_adj[b.first].insert({a.first, a.second+b.second});
            tmp_adj[i].clear();
        }
    }

    int next = 1;
    map<int,int> re_num;
    for(int i = 0; i < node_next; i++){
        if(tmp_adj[i].size() > 0){
            re_num[i] = next;
            next++;
        }
    }

    end_num = re_num[end_num];

    for(int i = 0; i < node_next; i++){
        for(auto edge : tmp_adj[i]){
            adj[re_num[i]].push_back({re_num[edge.first], edge.second});
        }
    }
    return;
}

int dfs(int v, int dist, uint64_t proc){
    if(v == end_num){
        return dist;
    }
    if(((1LL<<v)&proc) > 0)
        return 0;
    proc = ((1LL<<v) | proc);
    int ret = 0;
    for(auto u : adj[v]){
        ret = max(ret, dfs(u.first,dist+u.second,proc));
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    END = {n-2,n-2};
    for(int i = 0; i < n; i++){
        cin >> lab[i];
    }

    vis[BEGIN.first][BEGIN.second] = true;
    node[BEGIN.first][BEGIN.second] = 1;

    make_better();

    // cout << end_num << endl;
    // for(int i = 0; i <= end_num; i++){
    //     cout << i << ": ";
    //     for(auto v : adj[i])
    //         cout << v.first << " " << v.second << "; ";
    //     cout << endl;
    // }

    cout << "res: " << dfs(1,0,0) + 2 << endl;

    return 0;
}