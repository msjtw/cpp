#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long int ll;

const ll SIZE = 200007;

ll tab[SIZE] {};
ll res = 0;

void merge(ll p, ll g, ll q, ll t[]){
    ll a = p, b = g;
    ll i = p;
    while(a < g && b < q){
        if(t[a] < t[b]){
            tab[i++] = t[a++];
        }
        else{
            tab[i++] = t[b++];
            res += g-a;
        }
    }
    while(a < g)
        tab[i++] = t[a++];
    while(b < q)
        tab[i++] = t[b++];
    for(ll k = p; k < q; k++)
        t[k] = tab[k];
}

void mergesort(ll p, ll q, ll t[]){
    if(p+1 != q){
        ll m = (p+q)/2;
        mergesort(p, m, t);
        mergesort(m, q, t);
        merge(p, m, q, t);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    ll p;
    cin >> p;
    
    while(p-->0){
        ll nums[SIZE] {};
        res = 0;
        ll n;
        cin >> n;
        for(ll i = 0; i < n; i++){
            cin >> nums[i];
        }
        mergesort(0,n,nums);
        cout << res << endl;
    }
    
}