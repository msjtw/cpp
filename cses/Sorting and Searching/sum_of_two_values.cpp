#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    map <int, int> num_map;
    vector <int> num;

    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        num.push_back(a);
        num_map[a] = i+1;
    }

    for(int i = 0 ; i < n; i++){
        if(num_map[x-num[i]] != 0 and num_map[x-num[i]] != i+1){
            cout << i+1 << " " << num_map[x-num[i]];
            return 0;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}