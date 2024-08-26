#include <iostream>
#include <vector>

using namespace std;

const int MX = 2e5+7;
const int LOG_MX = 18;

int boss[MX][LOG_MX];
int level[MX];

vector<int> adj[MX];

void dfs(int a, int p){
    for(int b : adj[a]){
        if(b == p)
            continue;
        level[b] = level[a]+1;
        boss[b][0] = a;
        dfs(b,a);
    }
}

void fill(){
    for(int i = 1; i < LOG_MX; i++){
        for(int k = 1; k < MX; k++){
            boss[k][i] = boss[boss[k][i-1]][i-1];
        }
    }
}

int up(int x, int k){
    int exp = 0;
    while(k > 0){
        if(k & 1){
            x = boss[x][exp];
        }
        k >>= 1;
        exp ++;
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    fill();
    while(q-->0){
        //cout << "q: " << q << endl;
        int a, b, a2, b2;
        cin >> a >> b;
        if(level[a] > level[b])
            swap(a, b);
        a2=a;
        b2=b;
        b = up(b, level[b]-level[a]);
        if(a == b){
            cout << level[b2]-level[a2] << endl;
            continue;
        }
        //cout << a << " " << b << endl;
        for(int x = LOG_MX-1; x >= 0; x--){
            //cout << boss[a][0] << ", " << a << ", " << level[a] << "  |  " << boss[b][0] << ", " << b << ", " << level[b] << endl;
            while(boss[a][x] != boss[b][x]){
                //cout << "a";
                a = boss[a][x];
                b = boss[b][x];
            }
        }
        //cout << endl;
        int lca = boss[a][0];
        //cout << "\t" << lca << endl;
        cout << level[a2]+level[b2] - 2*level[lca] << endl;
    }
    return  0;
}
