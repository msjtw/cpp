#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    vector<int> arr;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    vector<int> res;

    for(int i = 0; i < n;i ++){
        auto it = lower_bound(res.begin(), res.end(), arr[i]);
        if(it == res.end())
            res.push_back(arr[i]);
        else{
            *it = arr[i];
        }
    }

    cout << res.size();

    return 0;
}