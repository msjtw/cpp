#include <iostream>

using namespace std;

struct node{
    int wart;
    int max;
};

node tree[1<<20];
int base = 1<<19;

int query(node drz_prz[], int p, int q){
    p += base;
    q += base;
    int l_max = 0;
    int r_max = 0;
    while(p > 0){
        l_max += drz_prz[p].wart;
        r_max += drz_prz[q].wart;
        if(p/2 != q/2){
            if(!(p&1)){
                l_max = max(l_max, drz_prz[p+1].max);
            }
            if(q&1){
                r_max = max(r_max, drz_prz[q-1].max);
            }
        }
        p >>= 1;
        q >>= 1;
    }
    return max(r_max, l_max);
}

void insert(node drz_prz[], int p, int q, int w){
    p += base ;
    q += base ;
    drz_prz[p].wart += w;
    drz_prz[p].max += w;
    if(p != q){
        drz_prz[q].wart += w;
        drz_prz[q].max += w;
    }
    while(p > 0){
        if(p/2 != q/2){
            if(!(p&1)){
                drz_prz[p+1].wart += w;
                drz_prz[p+1].max += w;
            }
            if(q&1){
                drz_prz[q-1].wart += w;
                drz_prz[q-1].max += w;
            }
        }
        if(p < base ){
            drz_prz[p].max = max(drz_prz[2*p].max + drz_prz[p].wart, drz_prz[2*p+1].max + drz_prz[p].wart);
            drz_prz[q].max = max(drz_prz[2*q].max + drz_prz[q].wart, drz_prz[2*q+1].max + drz_prz[q].wart);
        }
        p >>= 1;
        q >>= 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int miast, miejsc, p;
    cin >> miast >> miejsc >> p;
    int a, b, c;
    while(p--){
        cin >> a >> b >>c;
        a -= 1;
        b -= 2;
        if(query(tree, a, b)+c <= miejsc){
            cout << "T" << endl;
            insert(tree, a, b, c);
        }
        else{
            cout << "N" << endl;
        }
    }
    return 0;
}