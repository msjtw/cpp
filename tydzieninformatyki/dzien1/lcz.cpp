#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> zam(int p, int liczba){
    vector <int> wynik;
    while(liczba > 0){
        wynik.push_back(liczba%p);
        liczba/=p;
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}

int suma(vector <int> l){
    int ret = 0;
    for(int a : l)
        ret += a;
    return ret;
}

int main(){
    int p;
    cin >> p;
    while(p--){
        int maxi = 0;
        int po;
        int cyfra;
        int l;
        cin >> l;
        for(int i = 9; i > 1; i--){
            vector <int> pod = zam(i,l);
            int sum = suma(pod);
            if(sum > maxi){
                maxi = sum;
                cyfra = pod[2];
                po = i;
            }
        }
        cout << po << " " << cyfra << '\n';
    }
    return 0;
}