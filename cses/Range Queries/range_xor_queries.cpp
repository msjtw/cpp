#include <iostream>
#include <cctype>

using namespace std;

const int SIZE = 300007;

int val[SIZE*2] = {};

void set(int v, int p, int n){
    p += n;
    val[p] = v;
    p >>= 1;
    while(p >= 1){
        val[p] = val[p*2]^val[p*2+1];
        p >>= 1;
    }
}

int querry(int a, int b, int n){
    a += n;
    b += n;
    int res = 0;
    while(a <= b){
        if(a & 1){
            res = res ^ val[a];
            a ++;
        }
        if(!(b & 1)){
            res = res ^ val[b];
            b --;
        }
        a >>= 1;
        b >>= 1;
    }

    return res;
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
        int a ,b;
        cin >> a >> b;
        cout << querry(a-1, b-1, pow) << endl;
    }

    return 0;
}