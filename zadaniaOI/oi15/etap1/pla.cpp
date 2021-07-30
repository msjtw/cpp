#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);

    int p;
    cin >> p;
    stack <int> wys;
    int wyn = 0;
    p--;
    int w, h;
    cin >> w >> h;
    wys.push(h);
    while(p--){
        cin >> w >> h;
        while(wys.size() > 0 && wys.top() > h)
            wys.pop();
        if(wys.size() == 0 || wys.top() < h){
            wyn++;
            wys.push(h);
        }
    }

    cout << wyn+1 << endl;

    return 0;
}