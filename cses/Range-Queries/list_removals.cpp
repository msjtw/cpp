#include <iostream>

using namespace std;

const int BASE = 1<<18;

int tree[2*BASE];
int arr[BASE];

void insert(int p, int val){
    p += BASE;
    tree[p] = val;
    while(p > 0){
        p >>= 1;
        tree[p] = tree[2*p] + tree[2*p+1];
    }
}

int querry(int x){
    int p = 1;
    while(p < BASE){
        if(tree[2*p] > x){
            p = 2*p;
        }
        else{
            x -= tree[2*p];
            p = 2*p+1;
        }
    }
    return p-BASE;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        insert(i, 1);
    }
    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        a--;
        int idx = querry(a);
        cout << arr[idx] << " ";
        insert(idx, 0);
    }
    return 0;
}