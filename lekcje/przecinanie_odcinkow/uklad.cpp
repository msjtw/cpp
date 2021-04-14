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
    odc a,b,c,d;
    cin >> a.a.x >> a.a.y >> a.b.x >> a.b.y;
    cin >> b.a.x >> b.a.y >> b.b.x >> b.b.y;
    cin >> c.a.x >> c.a.y >> c.b.x >> c.b.y;
    cin >> d.a.x >> d.a.y >> d.b.x >> d.b.y;

    if(przecina(a,b) == 0 && przecina(a,d) == 0){
        cout << "niepoprawne przeciecie";
        return 0;
    }

    odc e = {b.b, d.a};
    if(przecina(a,e) == 2){
        cout << "po przeciwnych stronach";
        return 0;
    }

    cout << "po tej samej stronie";
    return 0;
}