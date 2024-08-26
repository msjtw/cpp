#include <iostream>

using namespace std;

const int MX = 2e5+7;
const int LOG_MX = 18;

int boss[MX][LOG_MX];

int main(){
    int n, q;
    cin >> n >> q;
    boss[1][0] = 0;
    for(int i = 2; i <= n; i++){
        cin >> boss[i][0];
    }
    for(int i = 1; i < LOG_MX; i++){
        for(int emp = 1; emp <= MX; emp++){
            boss[emp][i] = boss[boss[emp][i-1]][i-1];
        }
    }

    while(q --> 0){
        int x, k;
        cin >> x >> k;
        int exp = 0;
        while(k){
            if(k & 1){
                x = boss[x][exp];
            }
            exp ++;
            k >>= 1;
        }
        cout << (x == 0 ? -1 : x) << endl;
    }

    return 0;
}
