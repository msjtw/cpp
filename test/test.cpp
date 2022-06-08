#include <iostream>

using namespace std;

int n;

int licz(int x){
    if(x == 1)
        return 1;
    else{
        int w = licz(x/2);
        if(x%2 == 1)
            return w+1;
        else
            return w-1;
    }
}

int main(){
    for(int i = 1; i <= 50; i++)
        cout << i << " " << licz(i) << endl;
}