#include <iostream>
#include <string>

using namespace std;

int main(){
    int ky;
    cin >> ky;
    string a;
    cin.ignore(1, '\n');
    getline(cin, a);
    for(int i = 0; i < ky; i++){
        for(int k = i; k < a.size(); k += ky){
            cout << a[k];
        }   
    }

    return 0;
}