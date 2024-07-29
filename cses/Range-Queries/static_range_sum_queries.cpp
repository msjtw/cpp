#include <iostream>

using namespace std;

int main(){
    long long int sums[200007] {};
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> sums[i];
        sums[i] += sums[i-1];
    }
    while(q --> 0){
        int a, b;
        cin >> a >> b;
        cout << sums[b]-sums[a-1] << endl;
    }
    return 0;
}