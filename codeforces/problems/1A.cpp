// Theatre Square https://codeforces.com/problemset/problem/1/A

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int m, n , a;
    cin >> n >> m >> a;
    long long x = ceil(double(m)/a);
    long long y = ceil(double(n)/a);
    cout << x*y;
    return 0;
}