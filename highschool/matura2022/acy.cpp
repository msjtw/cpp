#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int w =0;
    map <string, int> liczby;

    for(int i = 0; i < 1000; i++){
        string a,b;
        cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        liczby[a]++;
        liczby[b]++;
    }

    for(auto a : liczby)
        w = max(w, a.second);

    cout << w;

    return 0;
}