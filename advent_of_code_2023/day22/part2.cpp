#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

struct point{
    int x, y, z;
};

vector<pair<point, point>> blocks;
vector<int> held_by[2000];
vector<int> holds[2000];

bool cmp(pair<point, point> l, pair<point, point> r){
    return l.first.z < r.first.z;
}

bool has_fallen[2000];

bool will_fall(int b){
    for(auto a : held_by[b])
        if(!has_fallen[a])
            return false;
    return true;
}
int fall(int a){
    if(holds[a].size() == 0)
        return 0;
    int ret = 0 ;
    has_fallen[a] = true;
    for(auto b : holds[a]){
        if(will_fall(b)){
            ret += fall(b)+1;
        }
    }

    return ret;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n;i ++){
        point a, b;
        cin >> a.x >> a.y >> a.z;
        cin >> b.x >> b.y >> b.z;
        if(b.z < a.z)
            swap(a,b);
        blocks.push_back({a,b});
    }

    sort(blocks.begin(), blocks.end(),cmp);

    pair<int,int> lvl[20][20];
    for(int i = 0; i < 20; i++){
        for(int k = 0; k < 20; k++){
            lvl[i][k] = {0, 0};
        }
    }

    for(int i = 0; i < blocks.size(); i++){
        int x1 = min(blocks[i].first.x, blocks[i].second.x);
        int x2 = max(blocks[i].first.x, blocks[i].second.x);
        int y1 = min(blocks[i].first.y, blocks[i].second.y);
        int y2 = max(blocks[i].first.y, blocks[i].second.y);
        int block_h = blocks[i].second.z - blocks[i].first.z + 1;
        int height = 0;
        set<int> blk;
        for(int x = x1; x <= x2; x++){
            for(int y = y1; y <= y2; y++){
                if(lvl[x][y].first > height){
                    height = lvl[x][y].first;
                    blk.clear();
                    blk.insert(lvl[x][y].second);
                }
                else if(lvl[x][y].first == height){
                    blk.insert(lvl[x][y].second);
                }
            }
        }
        for(int a : blk){
            held_by[i+1].push_back(a);
            holds[a].push_back(i+1);
        }
        for(int x = x1; x <= x2; x++){
            for(int y = y1; y <= y2; y++){
                lvl[x][y] = {height + block_h ,i+1};
            }
        }
    }

    int res = 0;

    for(int i = 1; i <= n; i++){
        for(int i = 0; i < 2000; i++){
            has_fallen[i] = false;
        }
        res += fall(i);
    }

    cout << res;

    return 0;
}