#include <iostream>
#include <queue>

using namespace std;

const int MOD = 1000000007;

bool grid[1007][1007] {};
int paths[1007][1007] {};

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int k = 0; k < s.length(); k++){
            if(s[k] == '*')
                grid[i+1][k+1] = true;
        }
    }
    // queue<pair<int, int>> q;
    // if(!grid[0][0])
    //     q.push({0,0});
    // while(!q.empty()){
    //     auto a = q.front();
    //     q.pop();
    //     paths[a.first][a.second]++;
    //     if(a.first < n and !grid[a.first+1][a.second])
    //         q.push({a.first+1, a.second});
    //     if(a.second < n and !grid[a.first][a.second+1])
    //         q.push({a.first, a.second+1});
    // }

    paths[0][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= n; k++){
            if(!grid[i][k])
                paths[i][k] = (paths[i-1][k] + paths[i][k-1])%MOD;
            else
                paths[i][k] = 0;
        }
    }

    cout << paths[n][n]%MOD;
}