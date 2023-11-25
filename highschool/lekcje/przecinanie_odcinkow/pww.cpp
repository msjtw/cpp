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
        return 1;

    return 0;
}

odc boki[50];
punkt w[50];

int main(){

    int wiez;
    int naj_y = -1000000;
    cin >> wiez;
    for(int  i = 0 ; i < wiez; i++){
        cin >> w[i].x >> w[i].y;
        naj_y = max(naj_y, w[i].y);
    }
    w[wiez] = w[0];

    for(int i = 0; i < wiez; i++){
        boki[i] = {w[i], w[i+1]};
    }

    odc spr;
    cin >> spr.a.x >> spr.a.y;
    spr.b.x = spr.a.x;
    spr.b.y = naj_y + 10;

    int prz = 0;

    for(int i = 0; i < wiez; i++){
        prz += przecina(spr, boki[i]);
    }

    if(prz&1)
        cout << "TAK";
    else
        cout << "NIE";
 
    return 0;
};