#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, m;
    vector <int> ch, dz;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        ch.push_back(a);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        dz.push_back(a);
    }

    sort(ch.begin(), ch.end());
    sort(dz.begin(), dz.end());

    int licznik = 0;

    for(int i = 0 ;i < ch.size(); i++){
        int k = 0;
        while(abs(dz[k]-ch[i]) > 1 && k < dz.size()){
            k++;
        }
        if(k != dz.size()){
            ch.erase(ch.begin()+i);
            i--;
            dz.erase(dz.begin()+k);
            licznik ++;
        }
    }
    cout << licznik;

    return 0;
}