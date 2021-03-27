#include <iostream>
#include <string>

using namespace std;

struct node{
    char c;
    node *prev;
};

node *first = NULL, *a;

void insert(char c){
    a = new node;
    a->c = c;
    a->prev = first;
    first = a;
}

bool test(char c){
    bool ret = false;
    if(first == NULL)
        return ret;
    
    if(c == ')' && first->c == '(')
        ret = true;
    else if(c == ']' && first->c == '[')
        ret = true;
    else if(c == '}' && first->c == '{')
        ret = true;

    a = first;
    first = first->prev;
    delete a;

    return ret;
}

int main(){
    string s;
    cin >> s;
    bool nie = false;

    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            insert(s[i]);
        else{
            if(!test(s[i])){
                nie = true;
                break;
            }
        }
    }

    if(first != NULL)
        nie = true;

    if(nie)
        cout << "blad";
    else
        cout << "poprawne";

    while(first != NULL){
        a = first;
        first = first->prev;
        delete a;
    }

    return 0;
}