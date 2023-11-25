#include <iostream>
#include <climits>

using namespace std;

struct node{
	int up;
	int right;
};

int wyn[57][57];
bool kier[57][57];
node odl[57][57];

int roz;

int main(){
	for(int i = 0; i < 57; i++){
		for(int k = 0; k < 57; k++){
			wyn[i][k] = INT_MAX;
		}
	}
	wyn[0][1] = 0;
	cin >> roz;

	int a, b, c, d, e;
	for(int k = 0; k < roz*(roz+1)*2; k++){
		cin >> a >> b >> c >> d >> e;
		if(a == c)
			odl[a][b].up = e;
		else
			odl[a][b].right = e;
	}

	int suma = 0;

    int i = 0, k = 0;
    while(i < roz || k < roz){
        suma+=odl[k][i].right;
        k++;
        suma+=odl[k][i].up;
        i++;
    }

    cout << suma;

  return 0;
}

