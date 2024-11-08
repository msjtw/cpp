#include<iostream>

using namespace std;

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    if(n <= 2){
        cout << 1 << endl << n;
        return 0;
    }
    int org_n = n;
    int sub = 2;
    int rest = 1;
    while(n  - sub > 0){
        n -= sub;
        rest += sub;
        sub++;
    }
    sub--;
    cout << sub << endl;
    int i = 1;
    for(; i < sub; i++){
        cout << i << " ";
    }
    cout << org_n - rest + sub << endl;

    return 0;
}

// 1:  1
// 2:  2
// 3:  1 2
// 4:  1 3
// 5:  1 4
// 6:  1 2 3
// 7:  1 2 4
// 8:  1 2 5
// 9:  1 2 6
// 10: 1 2 3 4
