#include<iostream>
#include<vector>

using namespace std;

vector<pair<double,double>> lines;
vector<pair<double,double>> limits;

const double MINI = 200000000000000;
const double MAXI = 400000000000000;

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
        if(vx > 0){
            limits.push_back({x,MAXI});
        }
        else{
            limits.push_back({MINI,x});
        }
    }

    int res = 0;

    for(int i = 0; i < lines.size(); i++){
        pair<double,double> a = lines[i];
        for(int k = i+1; k < lines.size(); k++){
            pair<double,double> b = lines[k];
            double x = (b.second-a.second)/(a.first-b.first);
            double y = a.first * x + a.second;

            double mi = max(limits[i].first, limits[k].first);
            double ma = min(limits[i].second, limits[k].second);

            if(x > mi and x < ma and y > MINI and y < MAXI)
                res++;
        }
    }

    cout << res;
    return 0;
}