#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> all;
vector<int> med;


int main(){
    int n;
    cin >> n;
    for(int i = 0; i< n; i++){
        int a;
        cin >> a;
        all.push_back(a);
        med.push_back(a);
    }
    sort(med.begin(), med.end());

    int m = med[med.size()/2];
    long long int res = 0;

    for(int a : all){
        res += abs(a-m);
    }

    cout << res;

    return 0;
}