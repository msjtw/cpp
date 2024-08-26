#include<iostream>

using namespace std;

typedef long long int ll;

int main(){
    int n;
    int x1,x2,y1,y2,xp,yp;
    int ax, ay, bx, by;
    cin >> n;
    while(n --> 0){
        cin >> x1 >> y1 >> x2 >> y2 >> xp >> yp;
        ax = x2-x1;
        ay = y2-y1;
        bx = xp-x2;
        by = yp-y2;
        ll cros = (ll)ax*by - (ll)bx*ay;
        if(cros > 0)
            cout << "LEFT\n";
        else if(cros == 0)
            cout << "TOUCH\n";
        else
            cout << "RIGHT\n";
    }
    return 0;
}
