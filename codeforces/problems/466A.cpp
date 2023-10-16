// https://codeforces.com/problemset/problem/466/A

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int p1 = n*a;
    int p2 = (n/m)*b + (n%m)*a;
    int p3 = ceil(double(n)/m) * b;
    cout << min(p1, min(p2, p3));
}
