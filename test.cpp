#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n;
    cin >> n;
    while(n --> 0){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end(), cmp);
    for(auto a : arr){
        cout << a << " ";
    }
}