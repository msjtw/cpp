#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct cow{
    int x;
    int y;
    int num;
    int sx = INT_MAX;
    int sy = INT_MAX;
};

int score[55];

cow north[55];
int n = 0;
cow east[55];
int e = 0;

int main(){
    int p;
    cin >> p;
    for(int i = 0; i < p ;i++){
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(c == 'N'){
            north[n] = {.x=x, .y=y, .num=i};
            n++;
        }
        else{
            east[e] = {.x=x, .y=y, .num=i};
            e++;
        }
        score[i] = INT_MAX;
    }

    













    for(int i = 0; i < n; i++){
        for(int j = 0; j < e; j++){
            if(east[j].y >= north[i].y &&  north[i].x >= east[j].x && east[j].y <= north[i].sy && north[i].x <= east[j].sx){
                if(east[j].y - north[i].y > north[i].x-east[j].x){
                    if(east[j].y - north[i].y < score[north[i].num]){
                        score[north[i].num] = east[j].y - north[i].y;
                        north[i].sy = east[j].y;
                    }
                }
                if(north[i].x-east[j].x > east[j].y - north[i].y){
                    if(north[i].x-east[j].x < score[east[j].num]){
                        score[east[j].num] = north[i].x-east[j].x;
                        east[j].sx = north[i].x;
                    }
                }
            }    
        }
    }

    for(int i = 0; i < p ;i++){
        if(score[i] < INT_MAX){
            cout << score[i] << endl;
        }
        else{
            cout << "Infinity" << endl;
        }
    }

    return 0;
}