#include <iostream>

using namespace std;

string mmap[133];
int n = 130;
int mem[133][133][4];

void zero(){
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            mem[i][k][0] = -1;
            mem[i][k][1] = -1;
            mem[i][k][2] = -1;
            mem[i][k][3] = -1;
        }
    }
}

void printmap(){
    for(int i = 0; i < n; i++){
        cout << mmap[i] << endl;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> mmap[i];
    }
    int sx, sy;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            if(mmap[i][k] == '^'){
                sx = k;
                sy = i;
            }
        }
    }

    int res = 0;

    for(int ii = 0; ii < n; ii++){
        for(int kk = 0; kk < n; kk++){
            cout << endl << ii << " " << kk << endl;
            if(mmap[ii][kk] == '#' or (ii == sy and kk == sx))
                continue;
            mmap[ii][kk] = '#';
            int x = sx, y = sy;
            int dir = 0;
            // printmap();
            zero();
            bool loop = false;
            bool finish = false;
            while(!finish){
                // cerr << x << ";" << y << " ";
                // up
                if(dir == 0){
                    if(mem[y][x][dir] == 1){
                        // cout << ii << " " << kk << endl;
                        finish = true;
                        loop = true;
                        break;
                    }
                    mem[y][x][dir] = 1;
                    while(mmap[y-1][x] != '#'){
                        mem[y][x][dir] = 1;
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
                    if(mem[y][x][dir] == 1){
                        // cout << ii << " " << kk << endl;
                        finish = true;
                        loop = true;
                        break;
                    }
                    mem[y][x][dir] = 1;
                    while(mmap[y][x+1] != '#'){
                        mem[y][x][dir] = 1;
                        x++;
                        if(x == 0 or y == 0 or x == n-1 or y == n-1){
                           finish = true;
                            break;
                        }
                    }
                    dir++;
                }
                // down
                else if(dir == 2){;
                    if(mem[y][x][dir] == 1){
                        // cout << ii << " " << kk << endl;
                        finish = true;
                        loop = true;
                        break;
                    }
                    mem[y][x][dir] = 1;
                    while(mmap[y+1][x] != '#'){
                        mem[y][x][dir] = 1;
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
                    if(mem[y][x][dir] == 1){
                        // cout << ii << " " << kk << endl;
                        finish = true;
                        loop = true;
                        break;
                    }
                    mem[y][x][dir] = 1;
                    while(mmap[y][x-1] != '#'){
                        mem[y][x][dir] = 1;
                        x--;
                        if(x == 0 or y == 0 or x == n-1 or y == n-1){
                            finish = true;
                            break;
                        }
                    }
                    dir = 0;
                }
            }

            if(loop)
                res++;
            mmap[ii][kk] = '.';
        }
    }


    
    cout << res;

}
