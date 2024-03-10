#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int ll;

vector<int> arr;

int main(){
    int n;
    cin >> n;
    ll total = 0;
    ll longest = 0;
    for(int i = 0 ; i < n ; i ++){
        ll a;
        cin >> a;
        arr.push_back(a);
        total += a;
        longest = max(longest, a);
    }

    cout << max(total, 2*longest);


    return 0;
}