#include<iostream>
#include<map>

using namespace std;

map<int,int> guests;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        guests[a]++;
        guests[b]--;
    }
    int maxi = 0;
    int res = 0;
    for(auto a : guests){
        res += a.second;
        maxi = max(maxi, res);
    }
    cout << maxi;
    return 0;
}