#include <iostream>
#include <bitset>

using namespace std;

const int MX = 2e5+7;

int dest[MX][37];


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    for(int i = 1 ; i <= n; i ++){
        cin >> dest[i][0];
    }

    for(int i = 1; i <= 32; i++){
        for(int k = 1; k <= n; k++){
            dest[k][i] = dest[dest[k][i-1]][i-1];
        }
    }

    while(q --> 0){
        unsigned int x, k;
        cin >> x >> k;
        for(int i = 0; i <= 30 ;i++){
            if((1 << i)&k){
                x = dest[x][i];
            }
        }
        cout << x << endl;
    }
    return 0;
}