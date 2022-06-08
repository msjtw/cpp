#include <iostream>

using namespace std;

int main(){
    int nrmin = 0;
    string mini = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
    int nrmax = 0;
    string maxi  = "0";

    for(int i = 1; i <= 1000; i++){
        string a;
        cin >> a;
        if(a.length() > maxi.length()){
            nrmax = i;
            maxi = a;
        }
        else if(a.length() == maxi.length()){
            int ka = 0, kmax = 0;
            while(maxi[kmax] == a[ka]){
                kmax++;
                ka++;
            }
            if(maxi[kmax] < a[ka]){
                nrmax = i;
                maxi = a;
            }
        }
        if(a.length() < mini.length()){
            nrmin = i;
            mini = a;
        }
        else if(a.length() == mini.length()){
            int kmin = 0, ka = 0;
            while(mini[kmin] == a[ka]){
                kmin++;
                ka++;
            }
            if(mini[kmin] > a[ka]){
                nrmin = i;
                mini = a;
            }
        }
    }

    cout << nrmin << endl << nrmax;

    return 0;
}