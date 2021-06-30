#include <iostream>
#include <string>

using namespace std;

struct odc{
    int p, q;
};

int seg, zap;

odc wyn[2000007] {};
bool liz[1000007] {};

odc zmiana_parz(int p, int q){
    int omv = 0;
    while(p+omv < q-omv){
        if(liz[p+omv] == 0)
            return {p+omv+1, q};
        if(liz[q-omv] == 0)
            return {p, q-omv-1};
        ++omv;
    }
    return {p, q};
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> seg >> zap;
    string liz_s;
    cin >> liz_s;

    for(int i = 0; i < (int)liz_s.size(); i++){
        liz[i+1] = (liz_s[i] == 'T' ? 1 : 0);
    }

    odc all1 = {1, seg};
    odc all2 = zmiana_parz(all1.p, all1.q);
    

    int sum1 = 0;
    for(int i = all1.p; i <= all1.q; i++){
        sum1 += (liz[i]+1);
    }
    int sum2 = 0;
    for(int i = all2.p; i <= all2.q; i++){
        sum2 += (liz[i]+1);
    }

    while(all1.p <= all1.q){
        wyn[sum1] = all1;
        if(liz[all1.p] == 1)
            all1.p++;
        else if(liz[all1.q] == 1)
            all1.q--;
        else{
            all1.p++;
            all1.q--;
        }
        sum1 -= 2;
    }

    while(all2.p <= all2.q){
        wyn[sum2] = all2;
        if(liz[all2.p] == 1)
            all2.p++;
        else if(liz[all2.q] == 1)
            all2.q--;
        else{
            all2.p++;
            all2.q--;
        }
        sum2 -= 2;
    }

    while(zap--){
        int a;
        cin >> a;
        if(wyn[a].p == 0)
            cout << "NIE" << endl;
        else
            cout << wyn[a].p << " " << wyn[a].q << endl;
    }

    return 0;
}