#include <iostream>

using namespace std;

int sum[1007][1007] {};

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        string l;
        cin >> l;
        for(int k = 0; k < l.length(); k++){
            sum[i+1][k+1] = sum[i][k+1] + sum[i+1][k] - sum[i][k];
            if(l[k] == '*')
                sum[i+1][k+1] += 1;
        }
    }

    while(q --> 0){
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        if(bx < ax)
            swap(ax, bx);
        if(by < ay)
            swap(ay, by);
        cout << sum[bx][by] - sum[bx][ay-1] - sum[ax-1][by] + sum[ax-1][ay-1] << endl;
    }

    return 0;
}