#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int SIZE = 1e5+7;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[SIZE];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int color[SIZE] {};
    vector<int> colors[SIZE];
    int curr = 1;
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            queue <int> bfs;
            color[i] = curr;
            colors[curr].push_back(i);
            bfs.push(i);
            while(!bfs.empty()){
                int p = bfs.front();
                bfs.pop();
                for(int v : adj[p]){
                    if(color[v] == 0){
                        color[v] = curr;
                        colors[curr].push_back(v);
                        bfs.push(v);
                    }
                }
            }
            curr++;
        }
    }

    cout << curr-2 << endl;

    // for(int i = 0; i < curr; i++){
    //     cout << i << ": ";
    //     for(int v : colors[i]){
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 1; i <= curr-2; i++){
        cout << colors[i][0] << " " << colors[i+1][0] << endl;
    }


    return 0;
}