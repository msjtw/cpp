#include <iostream>

using namespace std;

typedef long long int ll;

int main(){
    int n;
    cin >> n;
    ll div = 5;
    int res = 0;
    while(div <= n){
        res += n/div;
        div *= 5;
    }
    cout << res;
    return 0;
}
