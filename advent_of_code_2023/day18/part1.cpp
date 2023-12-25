#include <iostream>
#include <queue>

using namespace std;

const int SIZE = 600;

int map[SIZE][SIZE] {};

int x = 300;
int y = 300;

int main(){
    map[300][300] = 1;
    int n;
    cin >> n;
    while(n --> 0){
        string dir;
        int dist;
        string color;
        cin >> dir >> dist >> color;
        if(dir == "U"){
            while(dist --> 0){
                x--;
                map[x][y] = 1;
            }
        }
        if(dir == "D"){
            while(dist --> 0){
                x++;
                map[x][y] = 1;
            }
        }
        if(dir == "R"){
            while(dist --> 0){
                y++;
                map[x][y] = 1;
            }
        }
        if(dir == "L"){
            while(dist --> 0){
                y--;
                map[x][y] = 1;
            }
        }
    }

    for(int i = 0; i < SIZE; i ++){
        for(int k = 0; k < SIZE-1; k++){
            cout <<  map[i][k];
        }
        cout << endl;
    }

    queue<pair<int,int>> q;
    q.push({200,300});
    map[200][300] = 1;
    while(!q.empty()){
        auto f = q.front();
        q.pop();
        if(map[f.first-1][f.second] == 0){
            map[f.first-1][f.second] = 1;
            q.push({f.first-1, f.second});
        }
        if(map[f.first+1][f.second] == 0){
            map[f.first+1][f.second] = 1;
            q.push({f.first+1, f.second});
        }
        if(map[f.first][f.second-1] == 0){
            map[f.first][f.second-1] = 1;
            q.push({f.first, f.second-1});
        }
        if(map[f.first][f.second+1] == 0){
            map[f.first][f.second+1] = 1;
            q.push({f.first, f.second+1});
        }
    }

    int res= 0;
    for(int i = 0; i < SIZE; i ++){
        for(int k = 0; k < SIZE-1; k++){
            res += map[i][k];
        }
    }
    cout << res;
    return 0;
}