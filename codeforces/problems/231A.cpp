// Team https://codeforces.com/problemset/problem/231/A

#include <iostream>

using namespace std;

int main(){
    int p;
    cin >> p;
    int res = 0;
    while(p --> 0){
        int a, b, c;
        cin >> a >> b >> c;
        if(a+b+c > 1)
            res++;

    }

    cout << res;

    return 0;
}