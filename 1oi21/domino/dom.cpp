//Stanislaw Fiedler
//VIII LO Poznan

#include <iostream>

using namespace std;

long long int m;
long long int fib[200] {};

int main(){
    cin >> m;
    fib[1] = 1;
    fib[2] = 2;
    for(int i = 3; fib[i-1]+fib[i-2] < m; i++)
        fib[i] = fib[i-1]+fib[i-2];
    
    for(int i = 0; i < 100; i++){
        cout << fib[i] << " ";
    }

    int wyn = 0;
    

    return 0;
}