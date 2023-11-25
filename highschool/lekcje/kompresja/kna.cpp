#include <iostream>
#include <string>

using namespace std;

int main(){
    string linia;
    cin >> linia;
    int i = 1;
    while(i < (int)linia.size()){
        int ilosc = 1;
        while(linia[i] == linia[i-1] && i < linia.size()){
            i++;
            ilosc++;
        }
        if(ilosc > 3){
            cout << "#" << linia[i-1] << char(ilosc);
        }
        else{
            while(ilosc--){
                cout << linia[i-1];
            }
        }
        i++;
    }

    return 0;
}