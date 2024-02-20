#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int>> tasks;

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i ++){
        int a, b;
        cin >> a >> b;
        tasks.push_back({b, a});
    }

    return 0;
}