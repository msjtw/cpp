#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    int ilosc = 0;
    string odp;
    for(int i = 0; i < 1000; i++){
        string a, b, c, d;
        cin >> a >> b;
        c = a;
        d = b;
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());
        if(c == d){
            ilosc++;
            odp += (a + " " + b + "\n");
        }
    }
    cout << ilosc << endl << odp;
    return 0;
}