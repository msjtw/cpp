#include <iostream>
#include <algorithm>

using namespace std;

struct wyklad{
    int p, q;
};

wyklad wyk[10007] {};
int zam;

bool por(wyklad r, wyklad l){
    if(r.q != l.q)
        return r.q < l.q;
    else
        return r.p < l.p;
}

int bin(int w){
    int p = 0, q = zam;
    while(p < q){
        int m = (p+q+1)/2;
        if(w < wyk[m].q)
            q = m-1;
        else
            p = m;
    }
    return p;
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> zam;
    for(int i = 1; i <= zam; i++)
        cin >> wyk[i].p >> wyk[i].q;

    sort(wyk+1, wyk+zam+1, por);

    int czas[10007] {};

    for(int i = 1; i <= zam; i++){
        czas[i] = max(czas[i-1], czas[bin(wyk[i].p)]+(wyk[i].q-wyk[i].p));
    }

    cout << czas[zam] << endl;

    return 0;
}
