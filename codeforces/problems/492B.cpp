// https://codeforces.com/problemset/problem/492/B

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, l;
    cin >> n >> l;
    vector<int> p;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        p.push_back(a);
    }
    sort(p.begin(),p.end());
    double r = p[0];
    r = max(r, double(l-p[n-1]));
    for(int i = 0; i < n-1; i++){
        r = max(r, (p[i+1]-p[i])/2.0);
    }
    cout << fixed << r;
}