#include <iostream>

using namespace std;

int main(){
    int p;
    cin >> p;
    while(p --> 0){
        int a, b;
        cin >> a >> b;
        if(!(a&1) and !(b&1))
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }
}
