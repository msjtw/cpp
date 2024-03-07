#include<iostream>
#include<vector>

using namespace std;

const int MX = 2e5+7;

vector<int> adj[MX];

int len[MX][2];

void length_th(int x, int e, int v){
    len[x][0] = v;
    for(int b : adj[x]){
        if(b != e){
            length_th(b, x, v+1);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    

}