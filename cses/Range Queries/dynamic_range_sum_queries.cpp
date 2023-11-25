#include <iostream>

typedef long long int ll;

using namespace std;

const int SIZE = 300007;

long long val[SIZE*2] = {};

void set(int v, int p, int n){
    p += n;
    val[p] = v;
    p >>= 1;
    while(p >= 1){
        val[p] = val[p*2] + val[p*2+1];
        p >>= 1;
    }
}

ll sum(int a, int b, int n){
    a += n;
    b += n;
    ll s = 0;
    while(a <= b){
        if(a & 1){
            s += val[a];
            a ++;
        }
        if(!(b & 1)){
            s += val[b];
            b --;
        }
        a >>= 1;
        b >>= 1;
    }

    return s;
}

int main(){
    int n, q;
    cin >> n >> q;
    int pow = 1;
    while(pow < n)
        pow <<= 1;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        set(a, i, pow);
    }

    while( q --> 0){
        int t , a ,b;
        cin >> t >> a >> b;
        if(t == 1){
            set(b, a-1, pow);
        }
        else{
            cout << sum(a-1, b-1, pow) << endl;
        }
    }

    return 0;
}