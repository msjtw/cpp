#include <iostream>

using namespace std;

const int SIZE = 1e6+7;

int val[SIZE];
int pos[SIZE];

int main(){
    int n, p;
    cin >> n >> p;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        val[i] = a;
        pos[a] = i;
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        if(pos[i] > pos[i+1])
            res++;
    }

    while(p --> 0){
        int a, b;
        cin >> a >> b;
        int x = val[a];
        int y = val[b];
        if(x > y){
            swap(x, y);
            swap(a, b);
        }
        if(abs(x-y) == 1){
            if(pos[x-1] > pos[x])
                res--;
            if(pos[y-1] > pos[y])
                res--;
            if(pos[y] > pos[y+1])
                res--;
            swap(val[a], val[b]);
            swap(pos[x], pos[y]);
            if(pos[x-1] > pos[x])
                res++;
            if(pos[y-1] > pos[y])
                res++;
            if(pos[y] > pos[y+1])
                res++;
        }
        else{
            if(pos[x-1] > pos[x])
                res--;
            if(pos[y-1] > pos[y])
                res--;
            if(pos[x] > pos[x+1])
                res--;
            if(pos[y] > pos[y+1])
                res--;
            swap(val[a], val[b]);
            swap(pos[x], pos[y]);
            if(pos[x-1] > pos[x])
                res++;
            if(pos[y-1] > pos[y])
                res++;
            if(pos[x] > pos[x+1])
                res++;
            if(pos[y] > pos[y+1])
                res++;
        }
        cout << res << "\n";
    }

    return 0;
}