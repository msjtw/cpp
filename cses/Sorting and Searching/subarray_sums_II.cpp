#include<iostream>
#include<vector>
#include<map>

using namespace std;
typedef long long int ll;

vector<int> arr;
map<ll, int> sums;

int main(){
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n ; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    ll res = 0;
    ll prefix_sum = 0;
    sums[0] = 1;
    for(int a : arr){
        prefix_sum += a;
        res += sums[prefix_sum - s];
        sums[prefix_sum] ++;
    }

    cout << res;
    return 0;
}