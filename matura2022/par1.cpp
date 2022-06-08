#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct linia{
    int a;
    string s;
};

const int ILOSC = 100;

vector <linia> linie;

bool por(linia l, linia r){
    if(l.a != r.a)
        return l.a < r.a;
    return l.s < r.s;
}

int main(){
    for(int i = 0; i < ILOSC; i++){
        linia curr;
        cin >> curr.a >> curr.s;
        if(curr.a == curr.s.length())
            linie.push_back(curr);
    }

    sort(linie.begin(), linie.end(), por);
    cout << linie[0].a << " " << linie[0].s;

    return 0;
}