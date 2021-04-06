// Stanislaw Fiedler VIII LO Poznan

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int len, oper;
    cin >> len >> oper;

    vector <int> d_w;
    vector <int> d_z;
    for(int i = 0 ; i < 3; i++){
        d_z.push_back(0);
        d_w.push_back(0);
    }

    vector <int> suma;

    set <int> poz;
    
    string asd;
    cin >> asd;
    for(int i = 0; i < asd.length(); i++)
        d_w.push_back(asd[i]-'0');
    asd.clear();
    cin >> asd;
    for(int i = 0; i < asd.length(); i++)
        d_z.push_back(asd[i]-'0');

    
    for(int i = 0 ; i < (int)d_w.size(); i++){
        suma.push_back(d_w[i] + d_z[i]);
        if(suma[i] != 9)
            poz.insert(i);
    }

    while(oper--){
        char op;
        int p, pi;
        cin >> op >> pi;
        p = d_w.size() - pi;
        if(op == 'S'){
            int wyn = (d_w[p] + d_z[p]);
            auto tex = poz.upper_bound(p);
            int k = *tex;
            if(tex != poz.end() && suma[k] > 9)
                wyn += 1;
            cout << wyn%10 << endl;
        }
        else{
            int a;
            cin >> a;
            if(op == 'Z')
                d_z[p] = a;
            else
                d_w[p] = a;

            suma[p] = d_z[p] + d_w[p];

            if(suma[p] != 9)
                poz.insert(p);
            else
                poz.erase(p);
        }
    }

    return 0;
}