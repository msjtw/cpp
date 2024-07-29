#include<iostream>

using namespace std;

const int BASE = 1<<18;

// const int BASE = 1<<3;

typedef pair<int, int> pii;

int arr[2*BASE];

void insert(int tree[], int p, int val){
    p += BASE;
    tree[p] = val;
    while(p > 0){
        p >>= 1;
        tree[p] = max(tree[2*p], tree[2*p + 1]);
    }
}

void sub(int tree[], int p, int val){
    p += BASE;
    tree[p] -= val;
    while(p > 0){
        p >>= 1;
        tree[p] = max(tree[2*p], tree[2*p + 1]);
    }
}

int querry(int tree[], int val){
    int p = 1;
    while(p < BASE){
        if(tree[2*p] >= val){
            p = 2*p;
        }
        else{
            p = 2*p+1;
        }
    }
    if(tree[p] >= val)
        return p -= BASE;
    else
        return -1;
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        insert(arr, i, a);
    }

    for(int i = 0 ; i < m; i++){
        int a;
        cin >> a;
        int res = querry(arr, a)+1;
        cout << res << endl;
        sub(arr, res-1, a);
    }

    return 0;
}
