#include <iostream>
#include <cmath>

using namespace std;

const int MX = 1e6+1;
int divs[MX] {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, dd;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        cin >> a;
        for(int d = 1; d*d <= a; d++){
            if(a%d == 0){
                divs[d] ++;
                if(d*d != a)
                    divs[a/d] ++;
            }
        }
    }
    int res= 0;
    for(int i = 0; i < MX; i++){
        if(divs[i] >= 2){
            res = i;
        }
    }

    cout << res;

    return 0;
}
