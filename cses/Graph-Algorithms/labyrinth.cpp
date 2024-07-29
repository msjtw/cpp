#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct point{
    int x;
    int y;
};

char path[1007][1007];
int map[1007][1007];

int main(){
    ios_base::sync_with_stdio(false);

    int ax, ay, bx, by;
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i <= n; i++){
        map[0][i] = -1;
        map[m+1][i] = -1;
    }
    for(int i = 0; i <= m; i++){
        map[i][0] = -1;
        map[i][n+1] = -1;
    }

    for(int i = 0 ;i < n ;i++){
        string l;
        cin >> l;
        for(int k = 0; k < l.length(); k++){
            if(l[k] == 'A'){
                ax = k+1;
                ay = i+1;
            }
            if(l[k] == 'B'){
                bx = k+1;
                by = i+1;
            }
            if(l[k] == '#'){
                map[k+1][i+1] = -1;
            }
        }
    }

    // for(int i = 0; i < 15; i++){
    //     for(int k = 0; k < 15; k++){
    //         cout << map[k][i] << " ";
    //     }
    //     cout << endl;
    // }

    queue<point> q;
    q.push({ax,ay});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(map[p.x+1][p.y] == 0){
            q.push({p.x+1, p.y});
            map[p.x+1][p.y] = map[p.x][p.y] +1;
            path[p.x+1][p.y] = 'R';
        }
        if(map[p.x-1][p.y] == 0){
            q.push({p.x-1, p.y});
            map[p.x-1][p.y] = map[p.x][p.y] +1;
            path[p.x-1][p.y] = 'L';
        }
        if(map[p.x][p.y+1] == 0){
            q.push({p.x, p.y+1});
            map[p.x][p.y+1] = map[p.x][p.y] +1;
            path[p.x][p.y+1] = 'D';
        }
        if(map[p.x][p.y-1] == 0){
            q.push({p.x, p.y-1});
            map[p.x][p.y-1] = map[p.x][p.y] +1;
            path[p.x][p.y-1] = 'U';
        }
    }

    if(map[bx][by] != 0){
        cout << "YES" << endl;
        cout << map[bx][by] << endl;
        stack <char> res;
        while((ax != bx) or (ay != by)){
            res.push(path[bx][by]);
            if(path[bx][by] == 'R'){
                bx -= 1;
            }
            else if(path[bx][by] == 'L'){
                bx += 1;
            }
            else if(path[bx][by] == 'U'){
                by += 1;
            }
            else if(path[bx][by] == 'D'){
                by -= 1;
            }
        }
        while(!res.empty()){
            cout << res.top();
            res.pop();
        }
    }
    else{
        cout << "NO";
    }

    return 0;
}
