#include <iostream>

using namespace std;

const int MX = 2e5;
int arr[MX] {};

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int sum = 0;
    int ii = 0, kk = 0;
    while(kk < k){
        sum += arr[kk];
        kk++;
    }
    int mini = sum;
    int res = 1;
    /* cout << "---> " << ii << " " << kk << "  " << sum << endl; */
    while(kk < n){
        sum -= arr[ii];
        sum += arr[kk];
        ii++;
        kk++;
        /* cout << "---> " << ii << " " << kk << "  " << sum << endl; */
        if(sum < mini){
            mini = sum;
            res = ii+1;
        }
    }

    cout << res;

    return 0;
}
