#include<iostream>
#include<queue>

using namespace std;

string map[150] {};
int dist[150][150] {};
bool vis[150][150][5][15] {};

struct node
{
    int w;
    int x;
    int y;
    char d;
    int n;
    bool operator<(const node& rhs) const
    {

        return n < rhs.n;
    }
};

class Compare {
    public:
       bool operator()(node a, node b){
           if(a.w > b.w){
               return true;
           }
           return false;
      }
};

int main(){
    for(int i = 0; i < 150; i++){
        for(int k = 0; k < 150; k++){
            dist[i][k] = __INT_MAX__;
        }
    }
    dist[0][0] = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> map[i];
    }
    priority_queue<node,vector<node>, Compare> q;
    q.push({0,0,0,'R', 0});
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        if(p.x == n-1 and p.y == n-1)
            break;
        if(vis[p.x][p.y][p.d][p.n])
            continue;
        vis[p.x][p.y][p.d][p.n] = true;
        if(p.d == 'U'){
            if(p.x > 0 and p.n < 10){
                node p2 = {p.w+map[p.x-1][p.y]-'0',p.x-1,p.y,'U',p.n+1};
                // if(p2.w < dist[p2.x][p2.y]){
                //     dist[p2.x][p2.y] = p2.w;
                //     q.push(p2);
                // }
                dist[p2.x][p2.y] = min(p2.w, dist[p2.x][p2.y]);
                q.push(p2);
            }
            if(p.y > 0 and p.n >= 4){
                node p2 = {p.w+map[p.x][p.y-1]-'0',p.x,p.y-1,'L',1};
                // if(p2.w < dist[p2.x][p2.y]){
                //     dist[p2.x][p2.y] = p2.w;
                //     q.push(p2);
                // }
                dist[p2.x][p2.y] = min(p2.w, dist[p2.x][p2.y]);
                q.push(p2);
            }
            if(p.y < n-1 and p.n >= 4){
                node p2 = {p.w+map[p.x][p.y+1]-'0',p.x,p.y+1,'R',1};
                // if(p2.w < dist[p2.x][p2.y]){
                //     dist[p2.x][p2.y] = p2.w;
                //     q.push(p2);
                // }
                dist[p2.x][p2.y] = min(p2.w, dist[p2.x][p2.y]);
                q.push(p2);
            }
        }
        if(p.d == 'L'){
            if(p.y > 0 and p.n < 10){
                node p2 = {p.w+map[p.x][p.y-1]-'0',p.x,p.y-1,'L',p.n+1};
                // if(p2.w < dist[p2.x][p2.y]){
                //     dist[p2.x][p2.y] = p2.w;
                //     q.push(p2);
                // }
                dist[p2.x][p2.y] = min(p2.w, dist[p2.x][p2.y]);
                q.push(p2);
            }
            if(p.x > 0 and p.n >= 4){
                node p2 = {p.w+map[p.x-1][p.y]-'0',p.x-1,p.y,'U',1};
                // if(p2.w < dist[p2.x][p2.y]){
                //     dist[p2.x][p2.y] = p2.w;
                //     q.push(p2);
                // }
                dist[p2.x][p2.y] = min(p2.w, dist[p2.x][p2.y]);
                q.push(p2);
            }
            if(p.x < n-1 and p.n >= 4){
                node p2 = {p.w+map[p.x+1][p.y]-'0',p.x+1,p.y,'D',1};
                // if(p2.w < dist[p2.x][p2.y]){
                //     dist[p2.x][p2.y] = p2.w;
                //     q.push(p2);
                // }
                dist[p2.x][p2.y] = min(p2.w, dist[p2.x][p2.y]);
                q.push(p2);
            }
        }
        if(p.d == 'D'){
            if(p.x < n-1 and p.n < 10){
                node p2 = {p.w+map[p.x+1][p.y]-'0',p.x+1,p.y,'D',p.n+1};
                // if(p2.w < dist[p2.x][p2.y]){
                //     dist[p2.x][p2.y] = p2.w;
                //     q.push(p2);
                // }
                dist[p2.x][p2.y] = min(p2.w, dist[p2.x][p2.y]);
                q.push(p2);
            }
            if(p.y > 0 and p.n >= 4){
                node p2 = {p.w+map[p.x][p.y-1]-'0',p.x,p.y-1,'L',1};
                // if(p2.w < dist[p2.x][p2.y]){
                //     dist[p2.x][p2.y] = p2.w;
                //     q.push(p2);
                // }
                dist[p2.x][p2.y] = min(p2.w, dist[p2.x][p2.y]);
                q.push(p2);
            }
            if(p.y < n-1 and p.n >= 4){
                node p2 = {p.w+map[p.x][p.y+1]-'0',p.x,p.y+1,'R',1};
                // if(p2.w < dist[p2.x][p2.y]){
                //     dist[p2.x][p2.y] = p2.w;
                //     q.push(p2);
                // }
                dist[p2.x][p2.y] = min(p2.w, dist[p2.x][p2.y]);
                q.push(p2);
            }
        }
        if(p.d == 'R'){
            if(p.y < n-1 and p.n < 10){
                node p2 = {p.w+map[p.x][p.y+1]-'0',p.x,p.y+1,'R',p.n+1};
                // if(p2.w < dist[p2.x][p2.y]){
                //     dist[p2.x][p2.y] = p2.w;
                //     q.push(p2);
                // }
                dist[p2.x][p2.y] = min(p2.w, dist[p2.x][p2.y]);
                q.push(p2);
            }
            if(p.x > 0 and p.n >= 4){
                node p2 = {p.w+map[p.x-1][p.y]-'0',p.x-1,p.y,'U',1};
                // if(p2.w < dist[p2.x][p2.y]){
                //     dist[p2.x][p2.y] = p2.w;
                //     q.push(p2);
                // }
                dist[p2.x][p2.y] = min(p2.w, dist[p2.x][p2.y]);
                q.push(p2);
            }
            if(p.x < n-1 and p.n >= 4){
                node p2 = {p.w+map[p.x+1][p.y]-'0',p.x+1,p.y,'D',1};
                // if(p2.w < dist[p2.x][p2.y]){
                //     dist[p2.x][p2.y] = p2.w;
                //     q.push(p2);
                // }
                dist[p2.x][p2.y] = min(p2.w, dist[p2.x][p2.y]);
                q.push(p2);
            }
        }
    }
    cout << dist[n-1][n-1];
}