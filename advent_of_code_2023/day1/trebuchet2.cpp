#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> words = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
map<string, int> val;

void set_map(){
    int a = 1;
    for(string s : words){
        val[s] = a;
        a++;
    }
}

int main(){
    set_map();

    int res = 0;
    string s;
    while(cin >> s){
        int a, b;
        a = b = -1;
        for(int i = 0; i < s.length(); i++){
            if(isdigit(s[i])){
                if(a == -1 and s[i] != 0){
                    a = s[i] - '0';
                }
                b = s[i] - '0';
            }
            else{
                for(string num : words){
                    if(s.substr(i,num.length()) == num){
                        if(a == -1){
                            a = val[num];
                        }
                        b = val[num];
                        break;
                    }
                }
            }
        }
        res += a*10;
        res += b;
    }

    cout << res;

    return 0;
}