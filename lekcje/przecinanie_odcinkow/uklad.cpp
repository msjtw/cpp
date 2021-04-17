#include <iostream>

using namespace std;

struct punkt{
    int x, y;
};

struct odc{
    punkt a, b;
};

int znak(odc a, punkt b){
    int det = a.a.x*a.b.y + a.b.x*b.y + b.x*a.a.y - a.b.x*a.a.y - b.x*a.b.y - a.a.x*b.y;
    if(det > 0)
        return 1;
    else if(det == 0)
        return 0;
    else 
        return -1;
}

bool na(odc a, punkt c){
    if(min(a.a.x, a.b.x) <= c.x && c.x <= max(a.a.x, a.b.x))
        return true;
    else 
        return false;
}

int przecina(odc a, odc b){
    int det1 = znak(a, b.a);
    int det2 = znak(a, b.b);
    int det3 = znak(b, a.a);
    int det4 = znak(b, a.b);

    if(det1 == 0 && na(a, b.a))
        return 1;
    if(det2 == 0 && na(a, b.b))
        return 1;
    if(det3 == 0 && na(b, a.a))
        return 1;
    if(det4 == 0 && na(b, a.b))
        return 1;

    if(det1 == -1*det2 && det3 == -1*det4)
        return 2;

    return 0;
}

int main(){
    for(int i = 0 ;i < 5; i++){
        odc a;
        cin >> a.a.x >> a.a.y >> a.b.x >> a.b.y;

        punkt a1,b1,c1,d1;
        cin >> a1.x >> a1.y;
        cin >> b1.x >> b1.y;
        cin >> c1.x >> c1.y;
        cin >> d1.x >> d1.y;

        odc b = {a1, b1};
        odc c = {b1, c1};
        odc d = {c1, d1};


        if(przecina(a,b) == 0 || przecina(a,d) == 0){
            cout << 0;
            continue;
        }

        odc e = {b.b, d.a};
        if(przecina(a,e) == 2){
            cout << 2;
            continue;
        }

        cout << 1;
    }
    return 0;
}