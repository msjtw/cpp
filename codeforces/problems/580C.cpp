// https://codeforces.com/problemset/problem/580/C

#include <iostream>
#include <vector>

using namespace std;

bool cat[10007] {};
bool visited[10007] {};
vector <int> tree[10007];
int max_cats;

int res = 0;

void dfs(int a, int cats){
    visited[a] = true;
    bool leaf = true;
    for(int i = 0; i < tree[a].size(); i++){
        if(!visited[tree[a][i]] && cats+cat[tree[a][i]] <= max_cats){
            dfs(tree[a][i], cats+cat[tree[a][i]]);
            leaf = false;
        }
    }
    if(leaf)
        res++;
}

int main(){
    ios_base::sync_with_stdio(false);

    int v;
    cin >> v >> max_cats;
    for(int i = 0; i < v; i++){
        cin >> cat[i+1];
    }
    for(int i = 0; i < v-1; i++){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,cat[1]);
    cout << res;

    return 0;
}
