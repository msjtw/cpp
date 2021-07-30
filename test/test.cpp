#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int p;
    cin >> p;
    int zmien;
    cin >> zmien;
    vector <int> z;
    for(int i = 0; i < zmien; i++){
        int a;
        cin >> a;
        z.push_back(a);
    }

    cout << p << ":" << zmien << "|";
    for(int i = 0; i < zmien; i++){
        cout << z[i] << ":";
    }

    return 0;

}