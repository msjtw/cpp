#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n % 4 == 0){
        cout << "YES" << endl;
        cout << n/2 << endl;
        for(int i = 1, k = n; i < k; i+=2, k-=2){
            cout << i << " " << k << " ";
        }
        cout << endl << n/2 << endl;
        for(int i = 2, k = n-1; i < k; i+=2, k-=2){
            cout << i << " " << k << " ";
        }
        cout << endl;
    }
    else if((n+1)%4 == 0){
        cout << "YES" << endl;
        cout << n/2 << endl;
        cout << n << " ";
        for(int i = 2, k = n-2; i < k; i+=2, k-=2){
            cout << i << " " << k << " ";
        }
        cout << endl << n/2 + 1 << endl;
        for(int i = 1, k = n-1; i < k; i+=2, k-=2){
            cout << i << " " << k << " ";
        }
    }
    else{
        cout << "NO";
    }
    return 0;
}
