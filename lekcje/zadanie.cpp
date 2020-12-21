#include <iostream>
#include <algorithm>

using namespace std;

bool por(int l, int p){
    return  l < p;
}

int godziny[1000000] {};

int main(){
    int p,c = 0 ,czas;
    cin >> p;
    cin >> c;
    czas += c;
    cout << czas << endl;
    cin >> c;
    czas += c;
    cout << czas << endl;
    for(int i = 0; i < p; i++){
        int a, b;
        cin >> a >> b;
        godziny[i] = (a*60)+b;
    }

    sort(godziny, godziny+p, por);

    int m = 25*60;
    for(int i = 0; i < p-1; i++){
        m = min(m, godziny[i+1]-godziny[i]);
    }

    cout << (m+p)/60 << " " << (m+p)%60;

    // cout << m1/60 << " " << m1%60 << endl;
    // cout << m2/60 << " " << m2%60 << endl;


    return 0;
}