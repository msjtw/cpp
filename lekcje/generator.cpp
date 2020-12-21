#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));

    int p = 5;

    cout << p << endl;
    cout << rand()%3 << " " << rand()%60 << endl;

    for(int i = 0; i < p; i++){
        cout << rand()%24 << " " << rand()%60 << endl;
    }

    return 0;
}