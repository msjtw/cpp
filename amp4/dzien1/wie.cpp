#include <iostream>
#include <algorithm>

using namespace std;

int base = 1 << 19;

struct budynek{
    int wys, id;
};

struct zapytanie{
    int l, r, h;
    int id;
};

budynek wys[1000007] {};
zapytanie zap[1000007] {};
int tree[1<<20];
int odp[1000007] {};

bool por1(budynek l, budynek r){
     return l.wys < r.wys;
}

bool por2(zapytanie l, zapytanie r){
    return l.h < r.h;
}

void insert(int drz_prz[], int id, int val){
    int i = id + base;
    drz_prz[i] += val;
    while(i > 0){
        i >>= 1;
        drz_prz[i]++;
    }
}

int query(int el[], int b, int e){
    int res = 0;
        b += base;
        e += base;
        if(b == e) return el[b];
        res += el[b] + el[e];
        while(b + 1 < e) {
            if(!(b & 1)) res += el[b + 1];
            if(e & 1) res += el[e - 1];
            b >>= 1;
            e >>= 1;
        }
        return res;
}

int main(){
    ios_base::sync_with_stdio(0);

    int wierz, zapy;
    cin >> wierz >> zapy;

    for(int i = 0; i < wierz; i++){
        cin >> wys[i].wys;
        wys[i].id = i;
    }
    sort(wys, wys+wierz, por1);

    for(int i = 0; i < zapy; i++){
        cin >> zap[i].l >> zap[i].r >> zap[i].h;
        zap[i].l--;
        zap[i].r--;
        zap[i].id = i;
    }
    sort(zap, zap+zapy, por2);

    int k = 0;
    for(int i = 0; i < zapy; i++){
        while(wys[k].wys <= zap[i].h){
            insert(tree, wys[k].id, 1);
            k++;
        }
        odp[zap[i].id] = query(tree, zap[i].l, zap[i].r);
    }

    for(int i = 0; i < zapy; i++){
        cout << odp[i] << '\n';
    }

    return 0;
}