#include<iostream>

using namespace std;

int main(){
    int n, last;
    long long int res = 0;
    cin >> n >> last;
    for(int i = 1 ; i < n; i++){
        int a;
        cin >> a;
        if(a < last){
            res += (last - a);
        }
        else{
            last = a;
        }
    }
    cout << res;
    return 0;
}
