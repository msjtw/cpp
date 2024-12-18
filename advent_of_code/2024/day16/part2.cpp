#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

const int MX = 150;

string mmap[150];
int dist[MX][MX]; 
vector<vector<pii>> paths;
vector<pii> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void dfs(int x, int y, pii last_dir, vector<pii> hist, int len){
    if(mmap[y][x] == 'E'){
        paths.push_back(hist);
    }
    for(auto dir : dirs){
        if(mmap[y+dir.first][x+dir.second] != '#'){
            auto n_hist = hist;
            n_hist.push_back({x+dir.second, y+dir.first});
            if(last_dir != dir and dist[y+dir.first][x+dir.second] >= len+1001){
                dist[y+dir.first][x+dir.second] = hist.size();
                dfs(x+dir.second, y+dir.first, dir, n_hist, len+1001);
            }
            if(dist[y+dir.first][x+dir.second] >= len+1){
                dist[y+dir.first][x+dir.second] = hist.size();
                dfs(x+dir.second, y+dir.first, dir, n_hist, len+1);
            }
        }
    } 
}

int main(){
    for(int i = 0; i < MX; i++){
        for(int k = 0; k < MX; k++){
            dist[i][k] = __INT_MAX__;
        }
    }

    int n;
    int s_x, s_y;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> mmap[i];
        for(int k = 0; k < n; k++){
            if(mmap[i][k] == 'S'){
                s_x = k;
                s_y = i;
            }
        }
    }


    vector<pii> start = {{s_x,s_y}};
    dfs(s_x, s_y, make_pair(0,1), start, 0);

    cout << paths.size() << endl;
        
    return 0;
}
