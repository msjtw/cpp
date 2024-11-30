#include <iostream>

using namespace std;

string map[135];
string map2[135];

int main(){
    for(int i =0; i < 135; i++){
        cin >> map[i];
    }
    for(int i =0; i < 135; i++){
        cin >> map2[i];
    }
    int maxi = 0;
    long long int res= 0;
    for(int i = 0; i < 135; i++){
        for(int k = 0; k < 130; k++){
            if(int(map[i][k]) > int('!')){
                for(int u = 0; u < 135; u++){
                    for(int l = 0; l < 130; l++){
                        if(int(map[u][l]) > int('!')){
                            res += abs(u-i) + abs(l-k) + (abs(int(map[i][k])-int(map[u][l])) + abs(int(map2[i][k])-int(map2[u][l])) )*1e6;
                            maxi = max(maxi, abs(int(map[i][k])-int(map[u][l])));
                        }
                    }
                }
            }
        }
    }
    cout << maxi << endl;
    cout << res/2;
    return 0;
}