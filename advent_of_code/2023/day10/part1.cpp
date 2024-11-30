#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int SIZE = 140;

string map[SIZE] {};
int dist [SIZE][SIZE] {};
pair<int,int> start = {77, 110};

int main(){
    for(int i =0; i < SIZE; i++){
        cin >> map[i];
    }
    for(int i = 0; i < SIZE; i++){
        cout << map[i] << endl;
    }
    queue<pair<int,int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(map[p.first][p.second] == '|'){
            if(dist[p.first+1][p.second] == 0){
                dist[p.first+1][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first+1, p.second});
            }
            if(dist[p.first-1][p.second] == 0){
                dist[p.first-1][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first-1, p.second});
            }
        }
        if(map[p.first][p.second] == '-'){
            if(dist[p.first][p.second-1] == 0){
                dist[p.first][p.second-1] = dist[p.first][p.second] + 1;
                q.push({p.first, p.second-1});
            }
            if(dist[p.first][p.second+1] == 0){
                dist[p.first][p.second+1] = dist[p.first][p.second] + 1;
                q.push({p.first, p.second+1});
            }
        }
        if(map[p.first][p.second] == 'L'){
            if(dist[p.first-1][p.second] == 0){
                dist[p.first-1][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first-1, p.second});
            }
            if(dist[p.first][p.second+1] == 0){
                dist[p.first][p.second+1] = dist[p.first][p.second] + 1;
                q.push({p.first, p.second+1});
            }
        }
        if(map[p.first][p.second] == 'J'){
            if(dist[p.first-1][p.second] == 0){
                dist[p.first-1][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first-1, p.second});
            }
            if(dist[p.first][p.second-1] == 0){
                dist[p.first][p.second-1] = dist[p.first][p.second] + 1;
                q.push({p.first, p.second-1});
            }
        }
        if(map[p.first][p.second] == 'F'){
            if(dist[p.first][p.second+1] == 0){
                dist[p.first][p.second+1] = dist[p.first][p.second] + 1;
                q.push({p.first, p.second+1});
            }
            if(dist[p.first+1][p.second] == 0){
                dist[p.first+1][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first+1, p.second});
            }
        }
        if(map[p.first][p.second] == '7'){
            if(dist[p.first][p.second-1] == 0){
                dist[p.first][p.second-1] = dist[p.first][p.second] + 1;
                q.push({p.first, p.second-1});
            }
            if(dist[p.first+1][p.second] == 0){
                dist[p.first+1][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first+1, p.second});
            }
        }
    }
    int res = 0;
    for(int i = 0; i < SIZE; i++){
        for(int k = 0; k < SIZE; k++){
            res = max(res, dist[i][k]);
        }
    }
    cout << res;
    return 0;
}