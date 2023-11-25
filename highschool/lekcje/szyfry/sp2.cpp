#include <iostream>
#include <string>

using namespace std;

int main(){
    int kl, size;
    cin >> kl;
    cin.ignore(1, '\n');
    string a;
    getline(cin, a);

    while((int)a.size() % kl != 0)
        a += " ";

    for(int i = 0; i < kl; i++){
        for(int k = 0; k-1-i < (int)a.size(); k+=(2*kl)){
            if(k-1-i > 0)
                cout << a[k-1-i];
            if(k+i < (int)a.size())
                cout << a[k+i];
        }
    }

    return 0;
}
