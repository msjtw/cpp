#include <iostream>

using namespace std;

typedef long long int ll;

int main(){
    int n;
    cin >> n;
    for(ll k = 1; k <= n; k++){
        ll k2 = k*k;
        ll all = k2*(k2-1)/2;
        ll att = (k-2)*(k-1)*4;
        cout << all - att << endl;
    }

    return 0;
}
