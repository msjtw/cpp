#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int,int> l, pair<int,int>r){
    if(l.second == r.second)
        return l.first < r.first;
    else 
        return l.second < r.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> movies;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        movies.push_back({a,b});
    }

    sort(movies.begin(), movies.end(), cmp);

    int res = 0;
    int end_time = 0;

    //cout << endl;

    for(auto a : movies){
        //cout << a.first << " " << a.second << endl;
        if(a.first >= end_time){
            end_time = a.second;
            res++;
        }
    }

    cout << res;

    return 0;
}