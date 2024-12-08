#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

string mmap[55];
map<char, vector<pii>> locations;

int antinodes[55][55];

int count(int n){
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            res += antinodes[i][k];
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> mmap[i];
    }
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            if(mmap[i][k] != '.'){
                locations[mmap[i][k]].push_back({i,k});
            }
        }
    }

    for(int c = 0; c < 128; c++){
        if(locations.count(c) == 0)
            continue;
        vector<pii> pos = locations[c];
        for(int i = 0; i < pos.size(); i++){
            for(int k = 0; k < pos.size(); k++){
                if(i == k)
                    continue;
                int xdiff = pos[i].first - pos[k].first;
                int ydiff = pos[i].second - pos[k].second;
                int newx = pos[i].first + xdiff;
                int newy = pos[i].second + ydiff;
                if(newx >= 0 and newy >= 0 and newx < n and newy < n){
                    antinodes[newx][newy] = 1;
                }
            }
        }
    }

    cout << count(n);

    return 0;
}
