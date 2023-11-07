#include<iostream>
#include<vector>

using namespace std;

int main(){
    int c, s;
    cin >> c >> s;

    vector<int>coins;
    for(int i = 0 ; i < c; i++){
        int a;
        cin >> a;
        coins.push_back(a);
    }

    int ways[1000007] {};
    ways[0] = 1;

    for(int i = 1; i <= s; i++){
        for(auto a : coins){
            if(i-a >= 0){
                ways[i] += ways[i-a];
                ways[i] %= 1000000007;
            }
        }
    }

    cout << ways[s];

    return 0;
}