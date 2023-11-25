#include <iostream>

using namespace std;

int main(){
    string wyn = "";
    int first[500] {};
    for(int i = 0; i < 2000; i++){
        string a;
        char b;
        cin >> a >> b;
        if(a == "DOPISZ"){
            wyn += b;
        }
        if(a == "ZMIEN"){
            wyn[wyn.length()-1] = b;
        }
        if(a == "USUN"){
            wyn.erase(wyn.end()-1);
        }
        if(a == "PRZESUN"){
            int k = 0;
            for(; k < wyn.size() && wyn[k] != b; k++);
            wyn[k] += 1;
            if(wyn[k] > 'Z')
                wyn[k] = 'A';
        }
    }

    cout << wyn;
    
    return 0;
}