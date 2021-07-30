#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    string odp;
    stack <int> klocki;
    stack <int> temp;
    bool kolory[50007] {};
    int kolorow;
    cin >> kolorow;
    for(int i = 0; i < kolorow*2; i++){
        int a;
        cin >> a;
        klocki.push(a);
    }

    while(klocki.size() > 0){
        int a = klocki.top();
        klocki.pop();
        if(!kolory[a]){
            temp.push(a);
            kolory[a] = true;
        }
        else{
            int s = temp.size();
            int b = temp.top();
            temp.pop();
            kolory[b] = false;
            if(a != b){
                odp+=( to_string(s) + '\n');
                klocki.push(b);
                klocki.push(a);
            }
        }

    }

    cout << odp.size()/2 << endl;
    cout << odp;

    return 0;
}