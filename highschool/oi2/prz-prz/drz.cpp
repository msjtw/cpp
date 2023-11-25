#include <iostream>

using namespace std;

struct node{
    int wart;
    int suma;
};

node tree[1 << 4];
int base = 1 << 3;

int query(node drz_prz[], int p, int q){
    int ret = 0;
    int l_len = 0, r_len = (p != q ? 1 : 0), len = 1;
    p += base ;
    q += base ;
    while(q > 0){
        ret += drz_prz[p].wart*l_len + drz_prz[q].wart*r_len;
        if(p/2 != q/2){
            if(p%2 == 0){
                ret += drz_prz[p+1].suma;
                l_len += len;
            }
            if(q%2 == 1){
                ret += drz_prz[q-1].suma;
                r_len += len;
            }
        }
        p >>= 1;
        q >>= 1;
        len <<= 1;
    }
    return ret;
}

void insert(node drz_prz[], int p, int q, int w){
    int len = 1;
    p += base ;
    q += base ;
    drz_prz[p].wart += w;
    drz_prz[p].suma += w;
    if(p != q){
        drz_prz[q].suma += w;
        drz_prz[q].wart += w;
    }
    while(q > 0){
        if(p/2 != q/2){
            if(p%2 == 0){
                drz_prz[p+1].wart += w;
                drz_prz[p+1].suma += len*w;
            }
            if(q%2 == 1){
                drz_prz[q-1].wart += w;
                drz_prz[q-1].suma += len*w;
            }
        }
        if(p < base ){
            drz_prz[p].suma = drz_prz[2*p].suma + drz_prz[2*p+1].suma + len*drz_prz[p].wart;
            drz_prz[q].suma = drz_prz[2*q].suma + drz_prz[2*q+1].suma + len*drz_prz[q].wart;
        }
        p >>= 1;
        q >>= 1;
        len <<= 1;
    }
}

int main(){
    insert(tree, 1, 5, 5);
    insert(tree, 3, 4, 2);
    insert(tree, 5, 7, 5);
    insert(tree, 0, 0, 1);

    for(int i = 1; i < base*2; i++){
        cout << tree[i].wart << " ";
    }
    cout << endl;
    for(int i = 1; i < base*2; i++){
        cout << tree[i].suma << " ";
    }
    cout << endl;

    cout << query(tree, 1, 5) << endl;
    cout << query(tree, 0, 7) << endl;
    cout << query(tree, 6, 7) << endl;
}