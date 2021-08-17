#include <iostream>

using namespace std;

int NWZ[7][15007] {};
int memo[15007] {};

int main(){
    ios_base::sync_with_stdio(0);
    int len1, len2;
    cin >> len1 >> len2;
    int wyp1[15007], wyp2[15007];
    for(int i = 0; i < len1; i++)
        cin >> wyp1[i+1];
    for(int i = 0; i < len2; i++)
        cin >> wyp2[i+1];

    int pop1[15007], pop2[15007];
    for(int i = 1; i <= len1; i++){
        int k = i-1;
        while(k > 0 && wyp1[i] != wyp1[k])
            k--;
        pop1[i] = k;
    }
    for(int i = 1; i <= len2; i++){
        int k = i-1;
        while(k > 0 && wyp2[i] != wyp2[k])
            k--;
        pop2[i] = k;
    }

    for(int i = 1; i <= len1; i++){
        for(int k = 1; k <= len2; k++){
            if(wyp1[i] == wyp2[k] && pop1[i] > 0 && pop2[k] > 0)
                NWZ[i%2][k] = memo[pop2[k]] + 2;
            else
                NWZ[i%2][k] = 0;
            NWZ[i%2][k] = max(NWZ[i%2][k], max(NWZ[(i-1)%2][k], NWZ[i%2][k-1]));
        }
        for(int k = 1; k <= len2; k++)
            if(wyp1[i] == wyp2[k])
                memo[k] = NWZ[(i-1)%2][k-1];
    }

    cout << NWZ[len1%2][len2];

    return 0;
}