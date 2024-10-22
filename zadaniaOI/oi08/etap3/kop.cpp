#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int max, wart;
};
struct samor{
    int x, y;
    int war;
};

const int BASE = 2<<19;
node drz_prz[2<<20] {};

void insert(int p, int q, int w){
    p += BASE ;
    q += BASE ;
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
        if(p < BASE ){
            drz_prz[p].max = max(drz_prz[2*p].max, drz_prz[2*p+1].max) + drz_prz[p].wart;
            drz_prz[q].max = max(drz_prz[2*q].max, drz_prz[2*q+1].max) + drz_prz[q].wart;
        }
        p >>= 1;
        q >>= 1;
    }
}

int query(int p, int q){
    p += BASE;
    q += BASE;
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

bool por(samor l, samor r){
    if(l.y == l.y)
        return l.war > r.war;
    else
        return l.y < r.y;
}

int main(){
    int szer, wys;
    int samorodkow;
    cin >> szer >> wys;
    cin >> samorodkow;
    vector <samor> zloto;
    for(int i = 0; i < samorodkow; i++){
        int x, y;
        cin >> x >> y;
        x+=30000;
        y+=30000;
        zloto.push_back({x, y, 1});
        zloto.push_back({x, y+wys, -1});
    }
    sort(zloto.begin(), zloto.end(), por);

    int maxi = 0;
    for(auto a : zloto){
        insert(a.x, a.x+szer, a.war);
        maxi = max(maxi, query(0, 60000));
    }

    cout << maxi << endl;

    return 0;
}