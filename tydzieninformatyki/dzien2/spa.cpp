#include <iostream>
#include <vector>

using namespace std;

struct wek{
    int x, y;
};

int main(){
    ios_base::sync_with_stdio(0);
    int p;
    cin >> p;
    while(p--){
        bool kartka[1007][1007];
        vector <wek> stempel;
        int n, m, a, b;
        int xp = -1;
        int yp = -1;
        cin >> n >> m >> a >> b;
        for(int i = 0 ; i < n; i++){
            string s;
            cin >> s;
            for(int k = 0; k < s.length(); k++)
                kartka[i][k] = (s[k] == '.' ? 0 : 1);
        }
        stempel.push_back({0,0});
        for(int i = 0 ; i < a; i++){
            string s;
            cin >> s;
            for(int k = 0; k < s.length(); k++){
                if(s[k] == 'x'){
                    if(xp == -1){
                        xp = i;
                        yp = k;
                    }
                    else{
                        stempel.push_back({i-xp,k-yp});
                    }
                }
            }    
        }

        bool popsuted = false;
        for(int i = 0 ; i < n && !popsuted; i++){
            for(int k = 0; k < m && !popsuted; k++){
                if(kartka[i][k] == 1){
                    for(wek w : stempel){
                        if(i+w.x < 0 || k+w.y < 0 || i+w.x >= n || k+w.y >= m || kartka[i+w.x][k+w.y] == 0)
                            popsuted = true;
                        else
                            kartka[i+w.x][k+w.y] = 0;
                    }
                }
            }
        }
        cout << (popsuted ? "NIE\n" : "TAK\n");
    }
    
    return 0;
}