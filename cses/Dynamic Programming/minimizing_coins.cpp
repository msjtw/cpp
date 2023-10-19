#include<iostream>
#include<vector>
#include<limits>

using namespace std;

const int INT_MAX = __INT_MAX__-10;

vector <int> coins;
int num_coins, sum;

int DP[1000007] {};

int number(int val){
    if(val < 0)
        return INT_MAX;
    if(DP[val] != 0)
        return DP[val];
    if(val == 0)
        return 0;
    int mini = INT_MAX;
    for(int i = 0; i< coins.size(); i++){
        mini = min(mini, number(val - coins[i])+1);
    }
    DP[val] = mini;
    return mini;
}

int main(){
    
    cin >> num_coins >> sum;
    for(int i = 0; i < num_coins; i++){
        int a;
        cin >> a;
        coins.push_back(a);
    }
    int res = number(sum);
    cout << (res == INT_MAX ? -1 : res);
}