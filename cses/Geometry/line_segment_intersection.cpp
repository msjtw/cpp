#include <iostream>

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;

int cross(pii a, pii b, pii c){
    pii va, vb;
    va.first = b.first-a.first;
    va.second = b.second-a.second;
    vb.first = c.first-b.first;
    vb.second = c.second-b.second;
    return (ll)va.first*vb.second - (ll)vb.first*va.second;
}

bool ins(pii a, pii b, pii c, pii d){}


int main(){
    int q;
    cin >> q;
    while(q --> 0){
        pii a, b, c, d;
        cin >> a.first >> a.second;
        cin >> b.first >> b.second;
        cin >> c.first >> c.second;
        cin >> d.first >> d.second;
        if(a == c or a == d or b == c or b == d){
            cout << "YES\n";
        }
        else if(cross(a,b,c) != cross(a,b,d) and cross(c,d,a) != cross(c,d,b)){
            cout << "YES\n";
        }
        else if((cross(a,b,c) == 0 or cross(a,b,d) == 0 or cross(c,d,a) == 0 or cross(c,d,b) == 0) and ins(a,b,c,d)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}
