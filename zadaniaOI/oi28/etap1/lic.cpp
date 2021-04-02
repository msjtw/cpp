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
    vector <int> s (len);
    
    string asd;
    cin >> asd;
    for(int i = 0; i < asd.length(); ++i)
        d_w.push_back(asd[i]-'0');
    asd.clear();
    cin >> asd;
    for(int i = 0; i < asd.length(); ++i)
        d_z.push_back(asd[i]-'0');

    int carry = 0;
    for(int i = len-1; i > 0; --i){
        s[i] = (d_w[i-1] + d_z[i-1] + carry)%10;
        carry = (d_w[i-1] + d_z[i-1] + carry)/10;
    }
    s[0] = carry%10;

    bool popsuted = false;
    while(oper--){
        char op;
        int i, c;
        cin >> op;
        if(op != 'S'){
            cin >> i >> c;
            i = len-(i+1);
            if(op == 'W'){
                s[i+1] += c - d_w[i];
                d_w[i] = c;
            }
            else{
                s[i+1] += c - d_z[i];
                d_z[i] = c;
            }
            if(s[i+1] > 9){
                int jk = i+1;
                while(s[jk] > 9){
                    s[jk] -= 10;
                    s[jk-1] += 1;
                    jk--;
                }
            }
            else if(s[i+1] < 0){
                int jk = i+1;
                while(s[jk] < 0){
                    s[jk] += 10;
                    s[jk-1] -= 1;
                    jk--;
                }
            }

        }
        else{
            cin >> i;
            i = len-(i+1);
            cout << s[i+1] << '\n';
        }

    }

    return 0;
}