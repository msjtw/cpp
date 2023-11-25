#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 10;

void qwik_sort(int p, int q, int tab[]){
	int a = p, b = q;
	int m = tab[(p+q)/2]; 
	
	while(a <= b){
		while(m > tab[a])
            a++;
		while(m < tab[b])
            b--;
        if(a <= b){
            swap(tab[a],tab[b]);
                a++;
                b--;
        }
	}
	if(b > p)
	    qwik_sort(p, b, tab);
	if(a < q)
	    qwik_sort(a, q, tab);
}

int main(){
    srand(time(0));

    int t[SIZE];
    for(int i = 0; i < SIZE; i++)
        t[i] = rand()%100;

    qwik_sort(0, SIZE-1, t);

    for(int i = 0; i < SIZE; i++){
        cout << t[i] << " ";
    }

    return 0;
}