#include <iostream>
#include <algorithm>

using namespace std;

long long int needs[200007] {};
long long int rozm[200007] {};

int main(){
    ios_base::sync_with_stdio(false);
    int applicants, apartments, diff;
    cin >> applicants >> apartments >> diff;
    for(int i = 0; i < applicants; i++)
        cin >> needs[i];
    for(int i = 0; i < apartments; i++)
        cin >> rozm[i];
    
    sort(needs, needs+applicants);
    sort(rozm, rozm+apartments);

    int res = 0;

    int ap = 0;
    int per = 0;
    while(ap < apartments and per < applicants){
        if(rozm[ap]+diff < needs[per]){
            ap++;
        }
        else if(rozm[ap]-diff > needs[per]){
            per++;
        }
        else{
            per++;
            ap++;
            res++;
        }
    }
    cout << res;
}