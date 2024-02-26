#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int SIZE = 1007;
typedef pair<int,int> pii;

int n, m;

pair<int,int> A;
queue<pair<int,int>> monsters;

char map[SIZE][SIZE];

int dist_A[SIZE][SIZE];
int dist_mon[SIZE][SIZE];

void bfs_monst(){
    while(!monsters.empty()){
        pii p = monsters.front();
        monsters.pop();
        pii a = {p.first-1, p.second};
        if(map[a.first][a.second] == '.' and dist_mon[a.first][a.second] == __INT_MAX__){
            dist_mon[a.first][a.second] = dist_mon[p.first][p.second] +1;
            monsters.push(a);
        }
        a = {p.first+1, p.second};
        if(map[a.first][a.second] == '.' and dist_mon[a.first][a.second] == __INT_MAX__){
            dist_mon[a.first][a.second] = dist_mon[p.first][p.second] +1;
            monsters.push(a);
        }
        a = {p.first, p.second-1};
        if(map[a.first][a.second] == '.' and dist_mon[a.first][a.second] == __INT_MAX__){
            dist_mon[a.first][a.second] = dist_mon[p.first][p.second] +1;
            monsters.push(a);
        }
        a = {p.first, p.second+1};
        if(map[a.first][a.second] == '.' and dist_mon[a.first][a.second] == __INT_MAX__){
            dist_mon[a.first][a.second] = dist_mon[p.first][p.second] +1;
            monsters.push(a);
        }
    }
}

pii bfs_A(){
    queue<pii> q;
    q.push(A);
    while(!q.empty()){
        pii p = q.front();
        q.pop();
        if(dist_A[p.first][p.second] >= dist_mon[p.first][p.second]){
            continue;
        }
        if(p.first == 0 or p.second == 0 or p.first == n-1 or p.second == m-1){
            return p;
        }
        pii a = {p.first-1, p.second};
        if(map[a.first][a.second] == '.' and dist_A[a.first][a.second] == __INT_MAX__){
            dist_A[a.first][a.second] = dist_A[p.first][p.second] +1;
            map[a.first][a.second] = 'U';
            q.push(a);
        }
        a = {p.first+1, p.second};
        if(map[a.first][a.second] == '.' and dist_A[a.first][a.second] == __INT_MAX__){
            dist_A[a.first][a.second] = dist_A[p.first][p.second] +1;
            map[a.first][a.second] = 'D';
            q.push(a);
        }
        a = {p.first, p.second-1};
        if(map[a.first][a.second] == '.' and dist_A[a.first][a.second] == __INT_MAX__){
            dist_A[a.first][a.second] = dist_A[p.first][p.second] +1;
            map[a.first][a.second] = 'L';
            q.push(a);
        }
        a = {p.first, p.second+1};
        if(map[a.first][a.second] == '.' and dist_A[a.first][a.second] == __INT_MAX__){
            dist_A[a.first][a.second] = dist_A[p.first][p.second] +1;
            map[a.first][a.second] = 'R';
            q.push(a);
        }
    }

    return {-1,-1};
}

string path(pii start){
    string res {};
    while(start != A){
        res += map[start.first][start.second];
        if(map[start.first][start.second] == 'U'){
            start.first += 1;
        }
        else if(map[start.first][start.second] == 'D'){
            start.first -= 1;
        }
        else if(map[start.first][start.second] == 'L'){
            start.second += 1;
        }
        else if(map[start.first][start.second] == 'R'){
            start.second -= 1;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        for(int k = 0; k < m; k++){
            dist_A[i][k] = __INT_MAX__;
            dist_mon[i][k] = __INT_MAX__;
            cin >> map[i][k];
            if(map[i][k] == 'A'){
                A = {i,k};
                dist_A[i][k] = 0;
                map[i][k] = '.';
            }
            if(map[i][k] == 'M'){
                monsters.push({i,k});
                dist_mon[i][k] = 0;
                map[i][k] = '.';
            }
        }
    }

    bfs_monst();
    pii pos = bfs_A();
    if(pos == make_pair(-1,-1)){
        cout << "NO";
    }
    else{
        cout << "YES\n";
        string res = path(pos);
        cout << res.length() << "\n" << res;
    }

    return 0;
}