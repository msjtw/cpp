#include<iostream>

using namespace std;

typedef long long int ll;

const int BASE = 1<<18;

int emp[BASE];
int sal[2*BASE];

void add(int p, int val){
    p += BASE;
    sal[p] += val;
    while(p > 0){
        p >>= 1;
        sal[p] = sal[2*p] + sal[2*p+1];
    }
}

int query(int p, int q){
    int ret =0 ;
    p += BASE -1;
    q += BASE +1;
    while(p>>1 != q>>1){
        if(not(p&1)){
            ret += sal[p+1];
        }
        if(q&1){
            ret += sal[q-1];
        }
        p >>= 1;
        q >>= 1;
    }
    return ret;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a ;
        emp[i] = a;
        add(a, 1);
    }

    for(int i = 0 ; i < q; i++){
        char op;
        int a, b;
        cin >> op >> a >> b;
        if(op == '!'){
            add(emp[a], -1);
            emp[a] = b;
            add(emp[a], 1); 
        }
        else{
            cout << query(a, b) << " ";
        }
    }

    return 0;
}