#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MX =2e5+7;
vector<int> adj[MX];
int vals[MX];

int res[MX];

set<int> dfs(int a, int p){
    set<int> ret;
    ret.insert(vals[a]);
    for(int b : adj[a]){
        if(b == p)
            continue;
        set<int> r = dfs(b, a);
        if(r.size() > ret.size())
            swap(r, ret);
        auto it = r.begin();
        while(it != r.end()){
            ret.insert(*it);
            it++;
        }
    }
    res[a] = ret.size();
    return ret;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n; i++){
        cin >> vals[i];
    }
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    for(int i = 1; i <= n; i++)
        cout << res[i] << " ";

    return 0;
}
