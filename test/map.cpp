#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    map <string, int> mapa;
    //unordered_map <string, int> mapa;

    int t[100] = {};
    int b {};

    t {};

    mapa["slowo5"] ++;

    mapa["slowo"] = 1;
    mapa["slowo2"] = 2;
    mapa["slowo3"] = 3;
    mapa["slowo4"] = 4;

    mapa["slowo"] += 10;

    for(auto a : mapa){
        cout << a.first << " " << a.second << endl;
    }


    return 0;
}