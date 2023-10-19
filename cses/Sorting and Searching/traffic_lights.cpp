#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int len, lights;
    cin >> len >> lights;
    set<int> pos;
    multiset <int> dist;
    pos.insert(0);
    pos.insert(len);
    dist.insert(len);
    for(int i = 0; i < lights; i++){
        int a;
        cin >> a;
        auto ins = pos.insert(a);
        auto q = ins.first;
        auto p = q;
        auto r = q;
        r++;
        p--;
        dist.erase(dist.find(*r - *p));
        dist.insert(*q-*p);
        dist.insert(*r-*q);
        auto res = dist.end();
        res--;
        cout << *(res) << " ";
    }
    return 0;
}