#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> all;
long long int total_len = 0;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i< n; i++){
        int a;
        cin >> a;
        total_len += a;
        all.push_back(a);
    }
    int avg1 = total_len / n;
    int avg2 = ceil(total_len/(double)n);
    long long int res1 = 0;
    long long int res2 = 0;
    for(int a : all){
        res1 += abs(avg1 - a);
        res2 += abs(avg2 - a);
    }
    cout << min(res1, res2);
    return 0;
}