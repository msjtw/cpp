#include<iostream>
#include<vector>
#include<set>

using namespace std;

string map[200];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> map[i];
    }

    set<pair<int,int>> pos;
    pos.insert({65,65});

    for(int i = 0; i < 64; i++){
        set<pair<int,int>> q = pos;
        pos.clear();
        for(auto p : q){
            if(p.first > 0 and map[p.first-1][p.second] == '.'){
                pos.insert({p.first-1, p.second});
            }
            if(p.first < n-1 and map[p.first+1][p.second] == '.'){
                pos.insert({p.first+1, p.second});
            }
            if(p.second > 0 and map[p.first][p.second-1] == '.'){
                pos.insert({p.first, p.second-1});
            }
            if(p.second < n-1 and map[p.first][p.second+1] == '.'){
                pos.insert({p.first, p.second+1});
            }
        }
    }

    cout << pos.size();

    return 0;
}