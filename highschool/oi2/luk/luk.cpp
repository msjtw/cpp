#include <iostream>
#include <vector>

using namespace std;

vector <int> graf[300010];
int miast;

int spr(int miasto, int ekip, int ojciec){
    //cout << "a";
    int suma = 0;
    for(int i = 0; i < graf[miasto].size(); i++){
        if(graf[miasto][i] != ojciec)
            suma += spr(graf[miasto][i], ekip, miasto) +1;
    }
    return max(0, suma-ekip);
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> miast;
    int a, b;
    for(int i = 0; i < miast-1; i++){
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    int i = 0, k = miast;
    while(i < k){
        if(spr(1,(i+k)/2,0) == 0)
            k = ((i+k)/2);
        else
            i = ((i+k)/2)+1;
    }

    cout << i;

    return 0;
}