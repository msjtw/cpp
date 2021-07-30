#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);

    int p;
    cin >> p;

    char last = '-';
    while(p--){
        char c;
        cin >> c;
        if(c == '-'){
            if(last == '-')
                cout << "-";
            else if(last == '+')
                cout << ")-";
        }
        else{
            if(last == '-')
                cout << "(-";
            else if(last == '+')
                cout << "-";

        }
        last = c;
    }

    if(last == '+')
        cout << ")";

    return 0;
}