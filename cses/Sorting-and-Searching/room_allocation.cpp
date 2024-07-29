#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<tuple<int,int,int>> arr;
    int assign[(int)1e6+7];

    for(int i = 0; i < n ;i++){
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b, i});
    }

    sort(arr.begin(), arr.end());

    multiset<pair<int, int>> rooms;

    for(auto x : arr){
        auto it = rooms.lower_bound({get<0>(x),0});
        if(it == rooms.begin()){
            assign[get<2>(x)] = rooms.size()+1;
            rooms.insert({get<1>(x),rooms.size()+1});
            
        }
        else{
            it--;
            assign[get<2>(x)] = it->second;
            rooms.insert({get<1>(x),it->second});
            rooms.erase(it);
        }
    }

    cout << rooms.size() << endl;
    for(int i = 0 ; i < n ; i++){
        cout << assign[i] << ' ';
    }

    return 0;
}