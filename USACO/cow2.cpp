#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct cow{
    int px;
    int py;
    int x;
    int y;
    bool stuck;
    int num;
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
            north[n] = {x,y,x,y,false,i};
            n++;
        }
        else{
            east[e] = {x,y,x,y,false,i};
            e++;
        }
        score[i] = INT_MAX;
    }

    while

    return 0;
}