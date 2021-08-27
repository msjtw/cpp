#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);

    int liczb, wartosci;
    cin >> liczb >> wartosci;

    int lic = 1;
    int zmiana = wartosci;
    bool dod = true;
    cout << lic << " ";
    liczb--;
    while(zmiana){
        if(dod)
            lic += zmiana;
        else
            lic -= zmiana;
        dod = !dod;
        cout << lic << " ";
        liczb--;
        zmiana--;
    }
    int k = 2;
    while(liczb--){
        cout << wartosci+k << " ";
        k++;
    }

}