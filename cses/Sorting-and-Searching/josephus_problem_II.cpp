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

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        insert(1, i);
    }
    return 0;
}
