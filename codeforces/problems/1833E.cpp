#include<iostream>
#include<vector>

using namespace std;

const int SIZE = 200007;

vector<int> part[SIZE];
bool vis[SIZE] = {};
int maxi = 0;
int mini = 0;

void dfs(int a, bool vis[], vector<int>* part){
    vis[a] = true;
    for(int i = 0; i < part[a].size(); i++){
        if(!vis[part[a][i]]){
            dfs(part[a][i], vis, part);
        }
        else{
            maxi++;
        }
    }
}

int main(){
    int p;
    cin >> p;
    while(p --> 0){
        vector<int> partners[SIZE];
        bool visited[SIZE] {};
        
        int dancers;
        cin >> dancers;
        for(int i = 0; i < dancers; i++){
            int a;
            cin >> a;
            a--;
            partners[i].push_back(a);
            partners[a].push_back(i);
        }
        mini = 0;
        maxi = 0;
        for(int i = 0; i < dancers; i++){
            if(!vis[i]){
                mini++;
                dfs(i,visited, partners);
            }
        }
        cout << mini << " " << maxi << endl;
    }
    return 0;
}