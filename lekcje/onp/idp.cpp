// infiksowa do postfiksowej

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int pi[300];

stack <char> stos;

int main(){
    pi['='] = -1;
    pi['('] = 1;
    pi[')'] = 2;
    pi['+'] = 2;
    pi['-'] = 2;
    pi['*'] = 3;
    pi['/'] = 3;
    pi['^'] = 4;
    
    string linia;
    getline(cin, linia);
    int i = 0;
    while(i < (int)linia.size()-1){
        if(pi[linia[i]] == 0){
            cout << linia[i];
            if(pi[linia[i+1]] != 0)
                cout << " ";
            
        }
        else if(linia[i] == '('){
            stos.push(linia[i]);
        }
        else if(linia[i] == ')'){
            while((int)stos.size() > 0 && stos.top() != '('){
                cout << stos.top() << " " ;
                stos.pop();
            }
            stos.pop();
        }
        else{
            if(stos.size() == 0 || (stos.size() > 0 && pi[stos.top()] < pi[linia[i]]))
                stos.push(linia[i]);
            else{
                while((int)stos.size() > 0 && pi[stos.top()] >= pi[linia[i]]){
                    cout << stos.top() << " " ;
                    stos.pop();
                }
                stos.push(linia[i]);
            }
        }
        i++;
    }

    while(stos.size() > 0){
        cout << stos.top() << " " ;
        stos.pop(); 
    }

    return 0;
}