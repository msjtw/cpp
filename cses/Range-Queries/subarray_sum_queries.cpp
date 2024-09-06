#include<iostream>

using namespace std;

typedef long long int ll;

const int BASE = 1 << 18;

ll ssum[2*BASE];
ll prfx[2*BASE];
ll sufx[2*BASE];
ll tsum[2*BASE];

void insert(int val, int p){
    p+=BASE;
    ssum[p] = val;
    prfx[p] = val;
    sufx[p] = val;
    tsum[p] = val;
    int l, r;
    while(p){
        p >>= 1;
        l = 2*p;
        r = 2*p+1;
        tsum[p] = tsum[l] + tsum[r];
        prfx[p] = max(prfx[l], tsum[l] + prfx[r]);
        sufx[p] = max(sufx[l] + tsum[r], sufx[r]);
        ssum[p] = max(sufx[l] + prfx[r], max(ssum[l], ssum[r]));
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        insert(a, i);
    }
    while(m --> 0){
        int a, val;
        cin >> a >> val;
        insert(val, a);
        cout << max(max(ssum[1], prfx[1]),max(sufx[1], tsum[1])) << endl;
    }

}
