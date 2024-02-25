#include<iostream>
#include<set>
#include<queue>
#include<vector>

using namespace std;

char map[1007][1007];
bool monst_map[1007][1007];
bool vis[1007][1007];

pair<int,int> start;
vector <pair<int, int>> monsters;


int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= m; k++){
            cin >> map[i][k];
            if(map[i][k] == 'M'){
                monsters.push_back({i,k});
                map[i][k] = '.';
            }
            if(map[i][k] == 'A'){
                start = {i,k};
                map[i][k] = '.';
            }
        }
    }

    queue<pair<int,int>> q;
    q.push(start);
    while(!q.empty()){
        vector<pair<int,int>> mon = monsters;
        monsters.clear();
        for(auto a : mon){
            monst_map[a.first][a.second] = false;
            if(a.first > 1 and map[a.first-1][a.second] == '.' and !monst_map[a.first-1][a.second]){
                monsters.push_back({a.first-1, a.second});
                monst_map[a.first-1][a.second] = true;
            }
            if(a.first < n and map[a.first+1][a.second] == '.' and !monst_map[a.first+1][a.second]){
                monsters.push_back({a.first+1, a.second});
                monst_map[a.first+1][a.second] = true;
            }
            if(a.second > 1 and map[a.first][a.second-1] == '.' and !monst_map[a.first][a.second-1]){
                monsters.push_back({a.first, a.second-1});
                monst_map[a.first][a.second-1] = true;
            }
            if(a.second < m and map[a.first][a.second+1] == '.' and !monst_map[a.first][a.second+1]){
                monsters.push_back({a.first, a.second+1});
                monst_map[a.first][a.second+1] = true;
            }
        }
        int num = q.size();
        while(num--){
            auto p = q.front();
            q.pop();
            if(monst_map[p.first][p.second]){
                continue;
            }
            if(p.first == 1 or p.second == 1 or p.first == m or p.second == m){
                cout << "YES";
                return 0;
            }
            if(p.first > 0 and map[p.first-1][p.second] == '.' and !vis[p.first-1][p.second] and !monst_map[p.first-1][p.second]){
                q.push({p.first-1, p.second});
                vis[p.first-1][p.second] = true;
            }
            if(p.second <= n and map[p.first+1][p.second] == '.' and !vis[p.first+1][p.second] and !monst_map[p.first+1][p.second]){
                q.push({p.first+1, p.second});
                vis[p.first+1][p.second] = true;
            }
            if(p.second > 0 and map[p.first][p.second-1] == '.' and !vis[p.first][p.second-1] and !monst_map[p.first][p.second-1]){
                q.push({p.first, p.second-1});
                vis[p.first][p.second-1] = true;
            }
            if(p.second <= m and map[p.first][p.second+1] == '.' and !vis[p.first][p.second+1] and !monst_map[p.first][p.second+1]){
                q.push({p.first, p.second+1});
                vis[p.first][p.second+1] = true;
            }
        }
    }

    cout << "NO";

    return 0;
}