#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 2e5+7;

vector<int> arr;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    long long int sum = arr[0];
    long long int res = arr[0];
    for(int i = 1; i < n; i++){
        sum = max(sum + arr[i], (long long )arr[i]);
        res = max(res, sum);
    }
    cout << res;
    return 0;
}