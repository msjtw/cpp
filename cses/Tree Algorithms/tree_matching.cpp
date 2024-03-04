#include<iostream>
#include<vector>

using namespace std;

const int MX = 2e5+7;

vector<pair<int,int>> edges;
int num[MX];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a,b});
        num[a]++;
        num[b]
    }

    return 0;
}