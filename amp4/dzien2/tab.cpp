#include <iostream>

using namespace std;

long long int ilosc(long long int x, long long int m, long long int n){
    long long int wyn = 0;
    for(int i = 1; i <= m; i++)
        wyn += min(x/i, n);
    return wyn;
}

int main(){
    ios_base::sync_with_stdio(0);
    long long int n, m, k;
    cin >> m >> n >> k;

    long long int p = 1, q = m*n;

    while(p < q){
        long long c = p+(q-p)/2;
        if(ilosc(c, m, n) < k)
            p = c+1;
        else
            q = c;
    }

    cout << p;

    return 0;
}