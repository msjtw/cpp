#include <iostream>
#include <cmath>

using namespace std;

typedef long long int ll;

int main(){
    int q;
    cin >> q;
    while(q --> 0){
        ll a;
        cin >> a;
        ll num3 = 9;
        ll len = 1;
        ll last = 0;
        while(a - num3*len > 0){
            a -= num3*len;
            num3 *= 10;
            len++;
            last *= 10;
            last += 9;
        }
        ll num = ceil((double)a/len);
        ll num2 = a%len;
        /* num2++; */
        num += last;
        ll tmp = len;
        /* cout << tmp << " " << num2 << endl; */
        while(tmp%len != num2){
            num/=10;
            tmp--;
        }
        cout << num%10 << endl;
    }
    return 0;
}
