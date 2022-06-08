#include <iostream>
#include <cmath>

using namespace std;

struct punkt{
    int x, y;
};

int main(){
    int w = 0;
    int na = 0;
    int poza = 0;
    for(int i = 0; i < 1000; i++){
        int x, y;
        cin >> x >> y;
        x += 5000;
        y += 5000;
        if(x < 0 or y < 0 or x > 10000 or y > 10000)
            poza++;
        else if(x == 0 or x == 1000 or y == 0 or y == 10000)
            na++;
        else
            w++;
    }

    cout << w << endl <<  na << endl << poza;

    
    return 0;
}