#include <iostream>

using namespace std;

const int BASE = 1 << 18;

int arr[2*BASE];

void insert(int p, int val, int tree[]){
    p += BASE;
    tree[p] = val;
    while(p > 0){
        p>>=1;
        tree[p] = tree[2*p] + tree[2*p+1];
    }
}

int querry(int a, int b, int tree[]){
    a += BASE-1;
    b += BASE+1;
    int sum = 0;
    while(a>>1 != b>>1){
        if(!(a&1)){
            sum += tree[a+1];
        }
        if(b&1){
            sum += tree[b-1];
        }
        a>>=1;
        b>>=1;
    }
    return sum;
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        insert(1, i, arr);
    }
    for(int child = 0; child < n; child++){
        
    }
    return 0;
}
