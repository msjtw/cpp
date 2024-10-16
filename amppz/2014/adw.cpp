#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tiii;

vector <tiii> meetings[21];

bool cmp(tiii left, tiii right){
    return get<1>(left) < get<1>(right);
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        meetings[d].push_back({a,b,i+1});
    }

    for(int i = 1; i <= m; i++){
        sort(meetings[i].begin(), meetings[i].end(), cmp);
    }
    
    for (int i = 1; i <= m; i++) {
        int end = 0;
        vector<int> res;
        for (auto m : meetings[i]) {
            int a, b, idx;
            tie(a, b, idx) = m;
            if(a > end){
                res.push_back(idx);
                end = b;
            }
        }
        if(res.size() >= 2){
            cout << "TAK " << res[0] << " " << res[1] << endl;
        }
        else{
            cout << "NIE" << endl;
        }
    }

    return 0;
}
