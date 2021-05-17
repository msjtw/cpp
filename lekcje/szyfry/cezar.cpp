#include <iostream>
#include <string>

using namespace std;

int main(){
    string a;
    int p;
    getline(cin, a);
    cin >> p;
    for(int i =0 ;i < a.size()-1; i++){
        cout << char(a[i]+p);
    }
    return 0;
}
