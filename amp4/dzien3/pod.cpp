//SUS AMOGUS
#include <iostream>
#include <string>

using namespace std;

int main(){
    long long int wyn = 0;
    int n;
    cin >> n;
    string a;
    cin >> a;
    long long l = 0, r = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 'S')
            r ++;
    }
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 'S'){
            r--;
            l++;
        }
        if(a[i] == 'U')
            wyn += r*l;
    }

    cout << wyn;
    
    return 0;
}