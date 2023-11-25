#include <iostream>

using namespace std;

int silnia(int a){
    if(a == 1)
        return 1;
    else 
        return a * silnia(a-1);
}

int fib(int a){
    if(a == 0)
        return 0;
    else if(a == 1)
        return 1;
    else
        return fib(a-1) + fib(a-2);
}

int main(){
    int a;
    cin >> a;

    cout << silnia(a) << endl;
    cout << fib(a);

    return 0;
}