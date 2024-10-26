#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
        int a, b, c, p;
    cin >> p;
    while (p-->0) {
         cin >> a >> b >> c;
    int id = 1;
    for(int k = 0; k < b; k++)
    {
        for(int i = 0; i < a/3; i++){
            cout << id << " " << id << " " << id << " ";
        id++;
        }    
        cout << endl;
    }
        cout << endl;
    }
   
        return 0;
}
