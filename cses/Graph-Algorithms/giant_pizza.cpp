#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MX = 2e5+7;

vector<int> adj[MX];
vector<int> Tadj[MX];
stack<int> scc_stack;

int scc[MX];

bool vis[MX];
int scc_val[MX];

int not_node(int a){
    if(!(a&1))
        return a+1;
    else
        return a-1;
}

void dfs1(int a){
    vis[a] = true;
    for(int b : adj[a]){
        if(!vis[b])
            dfs1(b);
    }
    scc_stack.push(a);
}

void dfs2(int a, int scc_n){
    vis[a] = true;
    for(int b : Tadj[a]){
        if(!vis[b])
            dfs2(b, scc_n);
    }
    scc[a] = scc_n;
}

void zero(){
    for(int i = 0 ; i < MX; i++)
        vis[i] = false;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        char op;
        int a, b;
        cin >> op >> a;
        if(op == '+'){
            a *= 2;
        }
        else{
            a *= 2;
            a++;
        }
        cin >> op >> b;
        if(op == '+'){
            b *= 2;
        }
        else{
            b *= 2;
            b++;
        }
        Tadj[a].push_back(not_node(b));
        Tadj[b].push_back(not_node(a));
        adj[not_node(b)].push_back(a);
        adj[not_node(a)].push_back(b);
    }

    /* for(int i = 0; i < 10; i++){ */
    /*     cout << i << ": "; */
    /*     for(int a : adj[i]) */
    /*         cout << a << " "; */
    /*     cout << endl; */
    /* } */

    for(int i = 1 ; i <= 2*m+1; i++){
        if(!vis[i])
            dfs1(i);
    }

    zero();
    int scc_n = 1;
    while(!scc_stack.empty()){
        int a = scc_stack.top();
        scc_stack.pop();
        if(scc[a] == 0){
            /* cout << a << " " << scc_n << endl; */
            dfs2(a, scc_n);
            scc_n++;
        }
    }

    /* for(int i = 2; i <= 2*m+1; i++) */
    /*     cout << scc[i] << " "; */

    for(int i = 2; i <= m*2; i+=2){
        if(scc[i] == scc[i+1]){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    // 1 - false; 2 - true;
    for(int i = 2; i <= 2*m; i+=2){
        int a = scc[i];
        int b = scc[i+1];
        if(scc_val[a] != 0){
            scc_val[b] = (scc_val[a] == 1 ? 2 : 1);
        }
        if(scc_val[b] != 0){
            scc_val[a] = (scc_val[b] == 1 ? 2 : 1);
        }
        if(a < b){
            scc_val[a] = 1;
            scc_val[b] = 2;
        }
        else{
            scc_val[a] = 2;
            scc_val[b] = 1;
        }
    }

    for(int i = 2; i <= m*2; i+=2)
        cout << (scc_val[scc[i]] == 2 ? "+" : "-") << " ";

    return 0;
}
