#include <iostream>
#include <climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);

    int tuba[300007] {};
    tuba[0] = INT_MAX;

    int wys, kra;
    cin >> wys >> kra;

    for(int i = 0; i < wys; i++){
        int a;
        cin >> a;
        tuba[i+1] = min(tuba[i], a);
    }

    int k = wys;
    while(kra-- && k > 0){
        int a;
        cin >> a;
        while(k > 0 && tuba[k] < a)
            k--;
        k--;
    }

    cout << (k == 0 ? 0 : k+1);

    return 0;
}