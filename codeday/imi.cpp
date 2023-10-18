#include <iostream>
#include <cctype>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);

    map <char, int> wart;
    wart['k'] = 1;
    wart['M'] = 2;
    wart['G'] = 3;
    wart['T'] = 4;
    wart['P'] = 5;
    wart['B'] = 8;
    wart['b'] = 1;


    int p;
    cin >> p;
    while(p --> 0){
        string s;
        cin >> s;
        int k = 0;
        while(isdigit(s[k+1]))
            k++;
        long long int a = stoi(s.substr(0, k+1));
        a *= wart[s[s.length()-1]];
        int po = wart[s[s.length()-2]];
        while(po--)
            a *= 1024;
        cout << a << endl;
    }

    return 0;
}