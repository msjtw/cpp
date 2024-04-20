#include<iostream>

using namespace std;

const int MX = 1007;

int main(){
    int p;
    cin >> p;
    while(p-->0){
        int n,m;
        cin >> n >> m;
        string mapa[MX];
        string path_map[MX];
        for(int i = 0 ; i < m; i++){
            cin >> mapa[i];
        }
        string path;
        cin >> path;

        int x = 0, y = 0;
		int min_x{}, max_x{}, min_y{}, max_y{};
        
		for (auto &it : path) {
			//cout << it << endl;
			if (it == 'W') {
				y--;
			} else if (it == 'D') {
				x++;
			} else if (it == 'A') {
				x--;
			} else if (it == 'S') {
				y++;
			}
			//cout << x << ' ' << y << endl;
			min_x = min(min_x, x);
			max_x = max(max_x, x);
			min_y = min(min_y, y);
			max_y = max(max_y, y);
		}


        x = -min_y;
        y = -min_x;
        //cout << x << ' ' << y << endl;
        if(x < 0 or y < 0 or x >= m or y >= n ){
                cout << "INVALID" << endl;
                goto rome;
            }
            else if(mapa[x][y] == 0 or mapa[x][y] == 'X'){
                cout << "INVALID" << endl;
                goto rome;

            }
            else{
                mapa[x][y] = 0;
        }


        for(char c : path){
            if(c == 'W'){
                x--;
            }
            if(c == 'S'){
                x++;
            }
            if(c == 'D'){
                y++;
            }
            if(c == 'A'){
                y--;
            }
            if(x < 0 or y < 0 or x >= m or y >= n ){
                //cout << x << " " << y << endl;
                cout << "INVALID" << endl;
                goto rome;
            }
            else if(mapa[x][y] == 0 or mapa[x][y] == 'X'){
                cout << "INVALID" << endl;
                goto rome;

            }
            else{
                mapa[x][y] = 0;
            }
        }
        for(int i = 0 ; i < m; i++){
            for(int k = 0 ; k < n; k++){
                 if(mapa[i][k] != 0 and mapa[i][k] != 'X'){
                //     cout << x << ' ' << y << endl;
                //     cout << mapa[i][k] << endl;
                    cout << "INVALID" << endl;
                    goto rome;
                }
            }
        }
        cout << "VALID" << endl;
        rome:
    }
    return 0;
}