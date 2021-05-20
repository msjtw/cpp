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

	for(int i = 0; i < roz; i++){
        for(int k = 0; k < roz; k++){
            cout << odl[k][i].right << " " << odl[k][i].up << " ";
        }
        cout << odl[roz][i].up << endl;
    }
    for(int i = 0; i< roz; i++){
        cout << odl[i][roz].right << " ";
    }

  return 0;
}

