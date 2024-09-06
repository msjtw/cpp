#include <ios>
#include <iostream>

using namespace std;

const int MX = 2e5+7;

int res[MX];
int tp[MX];
int vis[MX];

int cpy_n = 0;
bool cpy = false;
int cycle = 0;
int dfs(int a){
    /* cout << a << endl; */
    int ret = 0;
    if(res[tp[a]] > 0){
        /* cout << 'a'; */
        ret = res[tp[a]] +1;
        cpy = true;
    }
    else if(vis[tp[a]] > 0){
        /* cout << 'b'; */
        cpy_n = tp[a];
        ret = 1;
        cycle = vis[a] - vis[tp[a]] +1;
    }
    else{
        /* cout << 'c'; */
        vis[tp[a]] = vis[a]+1;
        ret = dfs(tp[a])+1;
    }
    if(cpy_n == a)
        cpy = true;
    if(cpy){
        res[a] = ret;
    }
    else{
        res[a] = cycle;
    }
    vis[a] = 0;
    /* cout << a << " " << res[a] << " " << cpy_n << endl; */
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> tp[i];

    for(int i = 1; i <= n; i++){
        cpy = false;
        cpy_n = 0;
        cycle = 0;
        if(res[i] == 0){
            vis[i] = 1;
            dfs(i);
        }
    }

    for(int i = 1; i <= n; i++)
        cout << res[i] << " ";

    return 0;
}
