#include <iostream>

using namespace std;

typedef long long int ll;

int main(){
    int t;
    int x1,x2,x3,x4,y1,y2,y3,y4;
    cin >> t;
    while(t-->0){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        ll a1 = (ll)(y2-y1)*(x4-x3);
        ll a2 = (ll)(y4-y3)*(x2-x1);
        cout << a1 << " " << a2 << endl;
        if(a1 == a2){
            ll a3 = (ll)(y4-y3)*(x4-x3);
            ll a4 = (ll)(y2-y1)*(x2-x1);
            if(a3 == a4){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}
