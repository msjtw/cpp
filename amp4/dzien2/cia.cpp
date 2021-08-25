#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a;
    cin >> a;

    stack <long long> S;

    for(long long int i = 1; i*i <= a; i++){
        if(!(a%i)){
            cout << i << ' ';
            if(i*i != a)
                S.push(a/i);
        }
    }
    while(!S.empty()){
        cout << S.top() << ' ';
        S.pop();
    }

    return 0;
}