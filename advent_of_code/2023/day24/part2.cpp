#include<iostream>
#include<vector>

using namespace std;

typedef long long int ll;

struct hail{
    ll x, y, z;
    ll vx, vy, vz;
};

void solve(double m[][5]){
    for(int i = 0; i < 4;i ++){
        double a = 1.0/m[i][i];
        for(int k = i; k < 5; k++){
            m[i][k] *= a;
        }
        for(int j = 0; j < 4; j++){
            if(j == i)
                continue;
            a = -(m[j][i]);
            for(int l = 0; l < 5; l++){
                m[j][l] += a*m[i][l];
            }
        }

    }
}

vector<hail> hails;

void set_val1(double m[][5], vector<hail>& h){
    m[0][0] = h[1].vy - h[0].vy;
    m[1][0] = h[2].vy - h[1].vy;
    m[2][0] = h[3].vy - h[2].vy;
    m[3][0] = h[4].vy - h[3].vy;

    m[0][1] = h[0].y - h[1].y;
    m[1][1] = h[1].y - h[2].y;
    m[2][1] = h[2].y - h[3].y;
    m[3][1] = h[3].y - h[4].y;

    m[0][2] = h[0].vx - h[1].vx;
    m[1][2] = h[1].vx - h[2].vx;
    m[2][2] = h[2].vx - h[3].vx;
    m[3][2] = h[3].vx - h[4].vx;

    m[0][3] = h[1].x - h[0].x;
    m[1][3] = h[2].x - h[1].x;
    m[2][3] = h[3].x - h[2].x;
    m[3][3] = h[4].x - h[3].x;

    m[0][4] = h[1].x*h[1].vy - h[1].y*h[1].vx - h[0].x*h[0].vy + h[0].y*h[0].vx;
    m[1][4] = h[2].x*h[2].vy - h[2].y*h[2].vx - h[1].x*h[1].vy + h[1].y*h[1].vx;
    m[2][4] = h[3].x*h[3].vy - h[3].y*h[3].vx - h[2].x*h[2].vy + h[2].y*h[2].vx;
    m[3][4] = h[4].x*h[4].vy - h[4].y*h[4].vx - h[3].x*h[3].vy + h[3].y*h[3].vx;
}

void set_val2(double m[][5], vector<hail>& h){
    m[0][0] = h[1].vz - h[0].vz;
    m[1][0] = h[2].vz - h[1].vz;
    m[2][0] = h[3].vz - h[2].vz;
    m[3][0] = h[4].vz - h[3].vz;

    m[0][1] = h[0].z - h[1].z;
    m[1][1] = h[1].z - h[2].z;
    m[2][1] = h[2].z - h[3].z;
    m[3][1] = h[3].z - h[4].z;

    m[0][2] = h[0].vx - h[1].vx;
    m[1][2] = h[1].vx - h[2].vx;
    m[2][2] = h[2].vx - h[3].vx;
    m[3][2] = h[3].vx - h[4].vx;

    m[0][3] = h[1].x - h[0].x;
    m[1][3] = h[2].x - h[1].x;
    m[2][3] = h[3].x - h[2].x;
    m[3][3] = h[4].x - h[3].x;

    m[0][4] = h[1].x*h[1].vz - h[1].z*h[1].vx - h[0].x*h[0].vz + h[0].z*h[0].vx;
    m[1][4] = h[2].x*h[2].vz - h[2].z*h[2].vx - h[1].x*h[1].vz + h[1].z*h[1].vx;
    m[2][4] = h[3].x*h[3].vz - h[3].z*h[3].vx - h[2].x*h[2].vz + h[2].z*h[2].vx;
    m[3][4] = h[4].x*h[4].vz - h[4].z*h[4].vx - h[3].x*h[3].vz + h[3].z*h[3].vx;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        hail h;
        cin >> h.x >> h.y >> h.z;
        cin >> h.vx >> h.vy >> h.vz;
        hails.push_back(h);
    }

    double x = 0, y = 0, z = 0;

    double m[4][5];
    set_val1(m, hails);

    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 5; k++){
            cout << m[i][k] << " ";
        }
        cout << endl ;
    }
    cout << endl;

    solve(m);

    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 5; k++){
            cout << m[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;

    x = m[0][4];
    y = m[2][4];

    set_val2(m, hails);

    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 5; k++){
            cout << m[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;

    solve(m);

    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 5; k++){
            cout << m[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;

    z = m[2][4];

    cout << x << endl << y << endl << z << endl;
    cout << ll(x+y+z);

    return 0;
}
