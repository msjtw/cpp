#include<iostream>
#include<vector>

using namespace std;

vector<pair<double,double>> lines;
vector<pair<double,double>> start;

const double MINI = 200000000000000.0;
const double MAXI = 400000000000000.0;

// const double MINI = 7;
// const double MAXI = 27;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        double x, y, z;
        double vx, vy, vz;
        cin >> x >> y >> z;
        cin >> vx >> vy >> vz;
        double a = vy/vx;
        double b = y - (a*x);
        lines.push_back({a, b});
        start.push_back({x, vx});
    }

    int res = 0;

    for(int i = 0; i < lines.size(); i++){
        pair<double,double> a = lines[i];
        for(int k = i+1; k < lines.size(); k++){
            pair<double,double> b = lines[k];
            double x = (b.second-a.second)/(a.first-b.first);
            double y = a.first * x + a.second;

            double t1 = (x - start[i].first) / start[i].second;
            double t2 = (x - start[k].first) / start[k].second;

            if(t1 < 0 or t2 < 0)
                continue;

            if(x > MINI and x < MAXI and y > MINI and y < MAXI)
                res++;
        }
    }

    cout << res;
    return 0;
}