#include<iostream>
#include<vector>
#include<queue>

using namespace std;

pair<int,int> BEGIN = {1,1};
pair<int,int> END = {139,139};

int end_num = 0;
int next_node = 2;

string map[150];
int node[150][150];
bool vis[150][150];
vector<pair<int,int>> adj[10000];

void make_graph(pair<int,int> curr, int a, int len){

    int paths = 0;
    pair<int,int> next;
    next = {curr.first-1, curr.second};
    if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
        paths++;
    }
    next = {curr.first+1, curr.second};
    if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
        paths++;
    }
    next = {curr.first, curr.second-1};
    if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
        paths++;
    }
    next = {curr.first, curr.second+1};
    if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
        paths++;
    }

    if(paths == 0){
        if(curr == END)
            end_num = next_node;
        next = {curr.first-1, curr.second};
        if(node[next.first][next.second] != 0){
            adj[a].push_back({node[next.first][next.second], len+1});
            adj[node[next.first][next.second]].push_back({a, len+1});
            return;
        }
        next = {curr.first+1, curr.second};
        if(node[next.first][next.second] != 0){
            adj[a].push_back({node[next.first][next.second], len+1});
            adj[node[next.first][next.second]].push_back({a, len+1});
            return;
        }
        next = {curr.first, curr.second-1};
        if(node[next.first][next.second] != 0){
            adj[a].push_back({node[next.first][next.second], len+1});
            adj[node[next.first][next.second]].push_back({a, len+1});
            return;
        }
        next = {curr.first, curr.second+1};
        if(node[next.first][next.second] != 0){
            adj[a].push_back({node[next.first][next.second], len+1});
            adj[node[next.first][next.second]].push_back({a, len+1});
            return;
        }

        node[curr.first][curr.second] = next_node;
        adj[a].push_back({next_node, len});
        adj[next_node++].push_back({a, len});
    }
    else if(paths == 1){
        next = {curr.first-1, curr.second};
        if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            make_graph(next,a,len+1);
        }
        next = {curr.first+1, curr.second};
        if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            make_graph(next,a,len+1);
        }
        next = {curr.first, curr.second-1};
        if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            make_graph(next,a,len+1);
        }
        next = {curr.first, curr.second+1};
        if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            make_graph(next,a,len+1);
        }
    }
    else{
        node[curr.first][curr.second] = next_node;
        adj[a].push_back({next_node, len});
        adj[next_node].push_back({a, len});
        a = next_node;
        next_node++;
        next = {curr.first-1, curr.second};
        if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            make_graph(next,a,1);
        }
        next = {curr.first+1, curr.second};
        if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            make_graph(next,a,1);
        }
        next = {curr.first, curr.second-1};
        if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            make_graph(next,a,1);
        }
        next = {curr.first, curr.second+1};
        if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            make_graph(next,a,1);
        }
    }
    
}


void make_better(){
    int node_next = 2;
    queue<pair<pair<int,int>,int>> q;
    q.push({BEGIN,1});
    while(!q.empty()){
        auto curr = q.front().first;
        int a = q.front().second;
        q.pop();
        
        pair<int,int> next;
        next = {curr.first-1, curr.second};
        if(node[next.first][next.second] != 0){
            adj[a].push_back({node[next.first][next.second],1});
            adj[node[next.first][next.second]].push_back({a,1});
        }
        next = {curr.first+1, curr.second};
        if(node[next.first][next.second] != 0){
            adj[a].push_back({node[next.first][next.second],1});
            adj[node[next.first][next.second]].push_back({a,1});
        }
        next = {curr.first, curr.second-1};
        if(node[next.first][next.second] != 0){
            adj[a].push_back({node[next.first][next.second],1});
            adj[node[next.first][next.second]].push_back({a,1});
        }
        next = {curr.first, curr.second+1};
        if(node[next.first][next.second] != 0){
            adj[a].push_back({node[next.first][next.second],1});
            adj[node[next.first][next.second]].push_back({a,1});
        }


        next = {curr.first-1, curr.second};
        if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            node[next.first][next.second] = node_next;
            q.push({next, node_next});
            node_next++;
        }
        next = {curr.first+1, curr.second};
        if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            node[next.first][next.second] = node_next;
            q.push({next, node_next});
            node_next++;
        }
        next = {curr.first, curr.second-1};
        if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            node[next.first][next.second] = node_next;
            q.push({next, node_next});
            node_next++;
        }
        next = {curr.first, curr.second+1};
        if(!vis[next.first][next.second] and map[next.first][next.second] != '#'){
            vis[next.first][next.second] = true;
            node[next.first][next.second] = node_next;
            q.push({next, node_next});
            node_next++;
        }
    }

    for(int i = 1; i < node_next; i++){
        if(adj[i].size() == 2){
            adj[adj[i][0].first].erase({i, adj[i][0].second});
            adj[adj[i][0].first].push_back({adj[i][1].first, adj[i][0].second+adj[i][1].second});
            adj[adj[i][1].first].push_back({adj[i][0].first, adj[i][0].second+adj[i][1].second});
        }
    }

    for(int i = 0; i < node_next; i++){
        cout << i << ": ";
        for(auto v : adj[i])
            cout << v << " ";
        cout << endl;
    }
    return;
}

int maxi = 0;

int dfs(int v, int dist, u_int64_t proc){
    maxi = max(maxi, dist);
    if(v == end_num)
        return dist;
    if(((1<<v)&proc) > 0)
        return 0;
    proc = ((1<<v) | proc);
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
        cin >> map[i];
    }

    vis[BEGIN.first][BEGIN.second] = true;
    node[BEGIN.first][BEGIN.second] = 1;

    make_better();

    // make_graph(BEGIN, 1,0);

    // cout << end_num << endl;

    // for(int i = 0; i < n; i++){
    //     for(int k = 0; k < n; k++){
    //         if(node[i][k] > 0)
    //             cout << node[i][k];
    //         else
    //             cout << map[i][k];
    //     }
    //     cout << endl;
    // }

    // for(int i = 1; i < next_node; i++){
    //     cout << i << ": ";
    //     for(auto v : adj[i]){
    //         cout << v.first << " " << v.second << ";";
    //     }
    //     cout << endl;
    // }

    // cout << next_node-1 << endl;
    // cout << dfs(1,0,0) + 2 << endl;
    // cout << maxi;

    return 0;
}