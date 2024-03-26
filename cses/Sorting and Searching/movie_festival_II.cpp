#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<pii> movies;

bool por(pii l, pii r){
    return l.second < r.second;
}

multiset<int> members;

int main(){
    int m, k;
    cin >> m >> k;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        movies.push_back({a, b});
    }

    for(int i = 0; i < k; i++){
        members.insert(0);
    }

    int res = 0;

    sort(movies.begin(), movies.end(), por);

    for(pii mov : movies){
        auto it = members.upper_bound(mov.first);
        if(it == members.begin()){
            continue;
        }
        it--;
        members.erase(it);
        members.insert(mov.second);
        res++;
    }

    cout << res;

    return 0;
}