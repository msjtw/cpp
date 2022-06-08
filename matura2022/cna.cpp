#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){

    map <string, int> slowa;
    vector <string> kol;

    int p ;
    cin >> p;
    while(p --> 0){
        string a;
        cin >> a;
        slowa[a]++;
        if(slowa[a] == 1)
            kol.push_back(a);
    }

    for(string a : kol)
        if(slowa[a] > 1)
            cout << a << endl;




    return 0;
}