#include <iostream>
#include <utility>

using namespace std;

struct node{
    bool left;
    bool down;
};

node t[10007][10007];

void posdt(int n, int m){
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= m; k++){
            if(i == (n+1)/2)
                t[i][k] = {1, 1};
            else if(i < n)
                t[i][k] = {0, 1};
        }
    }
    t[(n+1)/2][m].left = false;
}

void wypisz(bool obr, int n, int m){
    for(int i = 1 ; i <= n; i++){
        for(int k = 1; k <= m; k++){
            if(t[i][k].down){
                if(obr)
                    cout << k << " " << i << " " << k << " " << i+1 << "\n";
                else
                    cout << i << " " << k << " " << i+1 << " " << k << "\n";
            }
            if(t[i][k].left){
                if(obr)
                    cout << k << " " << i << " " << k+1 << " " << i << "\n";
                else
                    cout << i << " " << k << " " << i << " " << k+1 << "\n";
            }
        }
    }
}

int snake1(int n, int m, int l){
    if(l > 0)
    return l;
}

int snake2(int n, int m, int l){
    return l;
}

int main(){
    ios_base::sync_with_stdio(0);

    int n, m, l;
    cin >> n >> m >> l;
    bool pm = !(m&1), pn = !(n&1);
    bool obr = false;
    if(l > (n*m-1)){
        cout << "NIE";
        return 0;
    }
    l -= (n+m-2);
    if(pm && pn)
        l++;
    if(l < 0){
        cout << "NIE";
        return 0;
    }
    if(pm && pn){
        posdt(n, m);
    }
    else{
        if(pn){
            obr = true;
            swap(m, n);
        }
        posdt(n, m);
        snake1(n, m, l);
        snake2(n, m, l);
    }

    wypisz(obr, n, m);
    
    return 0;
}