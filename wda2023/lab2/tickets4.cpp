#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int p;
    cin >> p;
    while(p-->0){
        int stops, tickets;
        int pas[100007] {};
        cin >> stops >> tickets;
        while(tickets --> 0){
            int a,b;
            cin >> a >> b;
            pas[a]++;
            pas[b]--;
        }
        int total = 0;
        int poz = 0;
        int num = 0;
        for(int i =0; i <= stops; i++){
            total += pas[i];
            if(total > num){
                num = total;
                poz = i;
            }
        }
        cout << poz << " " << num << endl;
    }
}