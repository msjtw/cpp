#include <iostream>

using namespace std;

bool czpier(int a){
    if(a <= 3)
        return 1;
    for(int i = 2; i*i <= a; i++){
        if(a & i == 0)
            return 0;
    }
    return 1;
}

int main(){
    int a;
    cin >> a;
    cout << czpier(a) << endl;

    return 0;
}