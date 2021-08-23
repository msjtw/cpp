#include <iostream>

using namespace std;

long long int nwdF(long long int a, long long int b){
    long long int pom;
    
	while(b!=0)
    {
		pom = b;
		b = a%b;
		a = pom;	
	}
	
    return a;
}

int main(){
    long long int nwd;
    bool pop = false, first = true;
    int p;
    cin >> p;
    while(p--){
        long long int a, b;
        cin >> a >> b;
        if(first){
            nwd = a;
            first = false;
        }
        if(a != b)
            pop = true;
        if(!pop){
            nwd = nwdF(nwd, a);
            cout << nwd << "\n";
        }
        else
            cout << 1 << '\n';
    }
    
    return 0;
}