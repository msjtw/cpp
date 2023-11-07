#include <iostream>
#include <cctype>

using namespace std;

int main(){
    int p;
    cin >> p;
    while(p-->0){
        string eq;
        cin >> eq;
        int num = 0;
        int x = 0;
        bool neg= false;
        bool after = false;
        int num_cons = 0;
        int i = 0;
        for(char c : eq){
            if(c == '-'){
                num += (num_cons * ((after ? !neg: neg) ? -1 : 1));
                num_cons = 0;
                neg = true;
            }    
            if(c == '+'){
                num += (num_cons * ((after ? !neg: neg) ? -1 : 1));
                num_cons = 0;
                neg = false;
            }
            if(c == 'x'){
                if(num_cons == 0 and i > 0 and eq[i-1] != '0')
                    num_cons = 1;
                if(i == 0)
                    num_cons = 1;
                if((after ? !neg: neg))
                    num_cons *= -1;
                x += num_cons;
                num_cons =0;
                neg = false;
            }
            if(isdigit(c)){
                num_cons *= 10;
                num_cons += (c -'0');
            }
            if(c == '='){
                num += (num_cons * ((after ? !neg: neg) ? -1 : 1));
                num_cons = 0;
                neg= false;
                after = true;
            }
            i++;
        }
        if(isdigit(eq[eq.size()-1])){
            num += (num_cons * ((after ? !neg: neg) ? -1 : 1));
        }

        if(x == 0)
            cout << "NO" << endl;
        else
            cout << (-1.0*num)/x << endl;
    }
}