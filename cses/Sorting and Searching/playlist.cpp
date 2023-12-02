#include<iostream>
#include<map>
#include<vector>

using namespace std;

map<int, int> val;
vector<int> arr;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    int i = 0;
    int k = 0;

    val[arr[i]] = 1;
    int res = 1;

    for(; i < n; i++){
        while(k < n-1 and val[arr[k+1]] == 0){
            val[arr[k+1]]++;
            k++;
        }
        res = max(res, k-i+1);
        val[arr[i]]--;
    }

    cout << res;
    return 0;
}