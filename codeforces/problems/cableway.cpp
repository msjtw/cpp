#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int r, g, b;
    cin >> r >> g >> b;

    r = ceil(r/2.0);
    g = ceil(g/2.0);
    b = ceil(b/2.0);
    /* cout << r << " " << g << " " << b << endl; */
    int maxi = max(max(r,g),b);
    int time  = (maxi-1)*3;
    /* cout << " " << maxi << " " << time  << endl; */
    if(b == maxi){
        time += 2;
    }
    else if(g == maxi){
        time += 1;
    }
    else if(r == maxi){
        time += 0;
    }

    cout << time+30;

    return 0;
}
