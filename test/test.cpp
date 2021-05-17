#include <iostream>
#include <string>

using namespace std;

int main(){
    int p;
    cin >> p;
    cin.ignore(1, '\n');
    string a;
    getline(cin, a);
    for(int i = 0; i < a.size(); i++){
        if(a[i] == ' ')
            a[i]= '%';
    }
    cout << p << "%" << a;
}