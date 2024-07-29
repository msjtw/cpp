#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 1)
        cout << 1;
    else if(n < 4){
        cout << "NO SOLUTION";
    }
    else if(n == 4){
        cout << "2 4 1 3";
    }
    else{
        int s = n/2+1;
        if(n % 2 == 1)
            s++;
        int a = 1;
        int b = s;
        while (a < s) {
            cout << a << " ";
            if(b <= n)
                cout << b << " ";
            a++;
            b++;
        }
    }
    return 0;
}
