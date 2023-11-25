#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

string kody[15] {};

int main(){
    for(int i = 0 ; i <10; i++){
        int a;
        string b;
        cin >> a >> b;
        kody[a] = b;
    }

    for(int i = 0; i < 500; i++){
        int p = 0, n = 0;
        string num;
        cin >> num;
        int a = stoi(num);
        while(a){
            p += a%10;
            a /= 10;
            n += a%10;
            a /= 10;
        }
        int suma = n + 3*p;

        suma %= 10;
        suma = 10-suma;
        suma %= 10;

        string wyn {};

        wyn += "11011010";
        for(char c : num)
            wyn += kody[c-'0'];
        wyn += kody[suma] + "11010110";

        cout << wyn << endl;
    }

    return 0;
}