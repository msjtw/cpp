#include<iostream>
#include<vector>

using namespace std;

const int MX = 2e5+7;

vector<int> adj[MX];

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