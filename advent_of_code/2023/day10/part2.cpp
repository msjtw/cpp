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
        bool in = false;
        for(int k = 0; k < SIZE; k++){
            dist[i][k] = (dist[i][k] > 0 ? 1: 0);
            map[i][k] = (dist[i][k] > 0 ? map[i][k]: '.');
        }
    }

    queue<pair<int,int>> q2;
    q2.push({0,0});
    while(!q2.empty()){
        auto p = q2.front();
        q2.pop();
        if(p.first > 0 && dist[p.first-1][p.second] == 0){
            dist[p.first-1][p.second] = 2;
            q2.push({p.first-1, p.second});
        }
        if(p.first < SIZE-1 && dist[p.first+1][p.second] == 0){
            dist[p.first+1][p.second] = 2;
            q2.push({p.first+1, p.second});
        }
        if(p.second > 0 && dist[p.first][p.second-1] == 0){
            dist[p.first][p.second-1] = 2;
            q2.push({p.first, p.second-1});
        }
        if(p.second < SIZE-1 && dist[p.first][p.second+1] == 0){
            dist[p.first][p.second+1] = 2;
            q2.push({p.first, p.second+1});
        }
    }

    for(int i = 0; i < SIZE; i++){
        bool in = false;
        //cout << map[i];
        for(int k = 0; k < SIZE; k++){
            if(dist[i][k] == 0){
                int sum = 0;
                for(int u = 0; u <= k; u++){
                    sum += (map[i][u] != '-' and map[i][u] != '.' ? 1 : 0);
                }
                if(sum %2 == 1){
                    dist[i][k] = 3; 
                    res ++;
                }
            }
            cout << dist[i][k];
        }
        cout << endl;
    }

    cout << res;
    return 0;
}