#include <iostream>
#include <cmath>

using namespace std;

const int SIZE = 200007;
const int LOG2_SIZE = 20;

int arr[SIZE][LOG2_SIZE] {};
int val[SIZE] {};

void pre(int n){
    for(int i = 0; i < n; i++){
        arr[i][0] = val[i];
    }
    for(int i = 1, pow = 1; pow <= n; i++, pow *= 2){
        for(int k = 0; k < n; k++){
            if(k + pow < n){
                arr[k][i] = min(arr[k][i-1], arr[k+pow][i-1]);
            }
        }
    }
}

int main(){

    int n, q;
    cin >> n >> q;
    for(int i = 0 ; i < n; i++){
        cin >> val[i];
    }

    pre(n);

    while(q --> 0){
        int a, b;
        cin >> a >> b;
        int l = b-a+1;
        int pow = 1;
        int k = 0;
        while(pow*2 <= l){
            pow *= 2;
            k++;    
        }
        cout << min(arr[a-1][k], arr[b-pow][k]) << endl;
    }

    return 0;
}