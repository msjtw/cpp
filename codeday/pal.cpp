#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int len;
    cin >> len;
    string s;
    cin >> s;
    int litery[500] {};
    for(auto a : s)
        litery[a]++;
    
    string w {};

    bool pop = false;

    for(int i = 0; i < 500; i++){
        if(litery[i] % 2 == 0){
            while(litery[i]){
                w = char(i) + w;
                w = w + char(i);
                litery[i] -= 2;
            }
        }
        else if(litery[i] % 2 == 1 && !pop){
            pop = true;
            string tp = "";
            while(litery[i]){
                tp += char(i);
                litery[i]--;
            }
            string tp2 = w.substr(0, w.size()/2);
            string tp3 = tp2;
            reverse(tp3.begin(), tp3.end());
            w= tp2 + tp + tp3;
        }
        else{
            cout << "NIE" << endl;
            return 0;
        }
    }

    cout << w << endl;

    return 0;
}