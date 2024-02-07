#include<iostream>
#include<vector>

using namespace std;

class what{
    public:
        int a;
        int b;
        void print();
        void set_c(int cc){c = cc;}
    private:
        int c;
        int mul(int);
};

void what::print(){
    cout << mul(a) + mul(b);
}

int what::mul(int z){
    return z*c;
}

what::what(){
    a = 1;
    b = 1;
    c = 1;
}

what::~what(){
    cout << "yoo mr. white";
}

int main(){
    what obj;
    obj.print();
    return 0;
}