#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string a;
    cin >> a;
    int zmian;
    cin >> zmian;

    vector <int> cyfry;
    for(int i = 0 ; i < a.length(); i++)
        cyfry.push_back(a[i] - '0');

    while(zmian){
        int maxi = 0;
        int poz = 0;
        for(int i = 0; i < min(zmian+1, (int)cyfry.size()); i++){
            if(cyfry[i] > maxi){
                maxi = cyfry[i];
                poz = i;
            }
        }
        cout << cyfry[poz];
        zmian -= poz;
        cyfry.erase(cyfry.begin()+poz); 
    }

    for(int n : cyfry)
        cout << n;

    return 0;
}