#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>> tasks;

bool cmp(pair<int,int> l, pair<int,int> r){
    if(l.first == r.first){
        return l.second < r.second;
    }
    return l.first < r.first;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i ++){
        int a, b;
        cin >> a >> b;
        tasks.push_back({a, b});
    }

    sort(tasks.begin(), tasks.end(), cmp);

    long long int res = 0;
    long long int end = 0;
    for(auto t : tasks){
        end += t.first;
        res += t.second - end;
    }

    cout << res;

    return 0;
}