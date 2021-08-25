#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    srand(time(NULL));

    int dni = 1000000;
    cout << dni << '\n';
    long long stan = 0;
    for(int i = 0; i < dni; i++){
        int wej = rand()%100000;
        stan += wej;
        int wyj = rand()%stan;
        stan -= wyj;
        cout << wej << " " << wyj << '\n';
    }

    return 0;

}