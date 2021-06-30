#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct n{
    string a;
    int il;
};

vector <n> nap;

int main(){
    int p;
    int il = 0;
    cin >> p;
    while(p--){
        string s;
        cin >> s;
        bool jest = false;
        for(int i = 0; i < nap.size(); i++)
            if(nap[i].a == s){
                nap[i].il++;
                jest = true;
                break;
            }

        if(!jest)
            nap.push_back({s, 1});
    }

    for(auto a : nap){
        if(a.il > 1)
            cout << a.a << endl;
    }

}