#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int maxi = 1;
    int curr = 1;
    for(int i = 1; i < s.length(); i++){
        if(s[i-1] == s[i]){
            curr++;
            maxi = max(maxi, curr);
        }
        else{
            curr = 1;
        }
    }
    cout << maxi;
    return 0;
}
