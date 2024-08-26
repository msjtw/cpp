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
    //cout.tie(0);
    int n, q;
    cin >> n >> q;
    boss[1][0] = 0;
    for(int i = 2; i <= n; i++){
        cin >> boss[i][0];
        adj[i].push_back(boss[i][0]);
        adj[boss[i][0]].push_back(i);
    }
    dfs(1,0);
    fill();
    while(q-->0){
        int a, b;
        cin >> a >> b;
        if(level[a] > level[b])
            swap(a, b);
        b = up(b, level[b]-level[a]);
        if(a == b){
            cout << a << endl;
            continue;
        }    
        int k = -1;
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
        cout << boss[a][0] << endl;
    }
    return  0;
}
