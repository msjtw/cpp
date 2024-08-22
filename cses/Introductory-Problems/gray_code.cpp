#include <iostream>
#include <bitset>

using namespace std;

const int MX = 1<<16;

int n;
bool mem[MX] {};

int flip(int s, int p){
    int t = 1 << p;
    if(s & t){
        return s & ~t;
    }
    else{
        return s | t;
    }
}

void gen(int s){
    mem[s] = true;
    for(int i = 0; i < n; i++){
        int tmp = flip(s, i);
        if(!mem[tmp])
            gen(tmp);
    }
    cout << bitset<16>(s).to_string().substr(16-n, n) << endl;
}

int main(){
    cin >> n;
    gen(0);
    return 0;
}
