#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);

     int n;
    cin >> n;
    while(n --> 0){
        int a, b;
        cin >> b >> a;
        cout << a*(b/3) << endl;
    }

    return 0;
}
