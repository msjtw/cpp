#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main(){
    vector<int> val;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        val.push_back(a);
    }
    sort(val.begin(), val.end());

    long long int res = 1;

    for(int i = 0; i < val.size(); i++){
        if(val[i] > res)
            break;
        res += val[i];
    }

    cout << res;

    return 0;
}