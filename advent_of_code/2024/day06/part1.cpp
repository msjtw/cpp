#include <iostream>

using namespace std;

string mmap[133];
int n = 130;

int count(){
    int ret = 0;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            if(mmap[i][k] == 'x')
                ret++;
        }
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> mmap[i];
    }
    int x, y;
    int dir;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            if(mmap[i][k] == '^'){
                x = k;
                y = i;
                dir = 0;
            }
        }
    }

    bool finish = false;
    while(!finish){
        // up
        if(dir == 0){
            cout << "up" << endl;
            while(mmap[y-1][x] != '#'){
                mmap[y][x] = 'x';
                y--;
                if(x == 0 or y == 0 or x == n-1 or y == n-1){
                    finish = true;
                    break;
                }
            }
            dir++;
        }
        // right
        else if(dir == 1){
            cout << "right" << endl;
            while(mmap[y][x+1] != '#'){
                mmap[y][x] = 'x';
                x++;
                if(x == 0 or y == 0 or x == n-1 or y == n-1){
                   finish = true;
                    break;
                }
            }
            dir++;
        }
        // down
        else if(dir == 2){
            cout << "down" << endl;
            while(mmap[y+1][x] != '#'){
                mmap[y][x] = 'x';
                y++;
                if(x == 0 or y == 0 or x == n-1 or y == n-1){
                    finish = true;
                    break;
                }
            }
            dir++;

        }
        // left
        else if(dir == 3){
            cout << "left" << endl;
            while(mmap[y][x-1] != '#'){
                mmap[y][x] = 'x';
                x--;
                if(x == 0 or y == 0 or x == n-1 or y == n-1){
                    finish = true;
                    break;
                }
            }
            dir = 0;
        }
    }

    cout << count()+1;

}
