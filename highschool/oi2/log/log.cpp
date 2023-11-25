#include <iostream>

using namespace std;

int tree[1<<20];

int kier, zap;
char a;
int b, c;
int base = 1;

void insert(int drz_prz[], int id, int val){
    int i = id + base;
    drz_prz[i] = val;
    while(i > 0){
        i >>= 1;
        drz_prz[i] = drz_prz[2*i] + drz_prz[2*i+1];
    }
}

int query(int drz_prz[], int p, int q){
    int ret = 0;
    p = p + base -1;
    q = q + base +1;
    while(p/2 != q/2){
        if(!p&1)
            ret += drz_prz[p+1];
        if(q&1)
            ret += drz_prz[q-1];
        p >>= 1;
        q >>= 1;
    } 
    return ret;
}

int main(){
    cin >> kier >> zap;
    while(base < kier)
        base <<= 1;
    for(int i = 0; i < zap; i++){
        cin >> a >> b >> c;
        if(a == 'U'){
            insert(tree,b, c);
        }
        else{
            cout << query(tree,b,c) << endl;;
        }
    }

    return 0;
}