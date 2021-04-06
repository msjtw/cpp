// Stanislaw Fiedler VIII LO Poznan

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int len, oper;
    cin >> len >> oper;

    vector <int> d_w;
    vector <int> d_z;
    
    string asd;
    cin >> asd;
    for(int i = asd.length()-1; i >= 0; i--)
        d_w.push_back(asd[i]-'0');
    asd.clear();
    cin >> asd;
    for(int i = asd.length()-1; i >= 0; i--)
        d_z.push_back(asd[i]-'0');

    for(int i = 0 ; i < 3; i++){
        d_z.push_back(0);
        d_w.push_back(0);
    }

    while(oper--){
        char op;
        int p;
        cin >> op >> p;
        p--;
        if(op == 'S'){
            int suma = (d_w[p] + d_z[p]);
            while(p > 0){
                p--;
                if(d_w[p] + d_z[p] > 9){
                    suma += 1;
                    break;
                }
                else if(d_w[p] + d_z[p] < 9){
                    break;
                }
            }
            cout << suma%10 << endl;
        }
        else{
            int a;
            cin >> a;
            if(op == 'Z')
                d_z[p] = a;
            else
                d_w[p] = a;
        }
    }

    return 0;
}