#include<iostream>

using namespace std;

int main(){
    int p;
    cin >> p;

    while(p --> 0){
        int a;
        cin >> a;
        long long int last = 1;
        for(int i = 1; i <= a; i++){
            last *= i;
            while(last % 10 == 0)
                last /= 10;
            last %= 10000;
            //cout << last << endl;
        }
        cout << last%10 << endl;
    }

    return 0;
}