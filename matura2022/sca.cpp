#include <iostream>
#include <queue>

using namespace std;

int wyn = 0;
queue <int> lines;

int t1[1007][1007] {};
int t2[1007][1007] {};

void spr(int k){
    for(int i = 0; i <= 1000; i++){
        if(t1[k][i] != t2[k][i])
            return ;
    }
    lines.push(k+1);
    wyn++;
}

int main(){

    for(int i = 0; i < 1000; i++){
        for(int k = 0; k < 10; k++){
            cin >> t1[i][k];
        }
    }

    for(int i = 0; i < 1000; i++){
        for(int k = 0; k < 10; k++){
            cin >> t2[i][k];
        }
    }

    for(int i = 0; i < 1000; i++){
        queue <int> wyn;
        int n = 0, m = 0;
        while(n < 10 && m < 10){
            if(t1[i][n] < t2[i][m]){
                wyn.push(t1[i][n]);
                n++;
            }
            else{
                wyn.push(t2[i][m]);
                m++;
            }
        }
        if(n < 10)
            while(n < 10)
                wyn.push(t1[i][n++]);
        if(m < 10)
            while(m < 10)
                wyn.push(t2[i][m++]);

        while(!wyn.empty()){
            cout << wyn.front() << " ";
            wyn.pop();
        }
        cout << endl;
    }

    return 0;
}