//wartosc postfiksowej

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack <double> Q;

    string op;
    while(cin >> op){
        if(op[0] >= '0' && op[0] <= '9'){
            Q.push(stoi(op));
        }
        else{
            double b = Q.top();
            Q.pop();
            double a = Q.top();
            Q.pop();
            double c;
            if(op == "+")
                c = a+b;
            else if(op == "-")
                c = a-b;
            else if(op == "*")
                c = a*b;
            else
                c = a/b;
            Q.push(c);
        }
        op.clear();
    }

    cout << Q.top();

    return 0;
}