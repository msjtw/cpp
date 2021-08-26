#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int t, n; cin >> t;
    while(t--){
        cin>>n;
        if(n == 1) cout << 2 <<endl;
        else if(n == 2) cout<< 16 <<endl;
        else if(n == 3) cout<< 32 <<endl;
        else cout << 4 << endl;
    }
  
}