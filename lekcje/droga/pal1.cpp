#include <iostream>
#include <climits>
#include <stack>
#include <tuple>

using namespace std;

struct node{
	int up;
	int right;
};

int wyn[1000][1000];
bool kier[1000][1000];
node odl[1000][1000];

int roz;

stack <pair<int, int>> st;

int energia;

int main(){
	for(int i = 0; i < 1000; i++){
		for(int k = 0; k < 1000; k++){
			wyn[i][k] = INT_MAX;
		}
	}
	wyn[0][1] = 0;
	cin >> roz;

	int a, b, c, d, e;
	for(int k = 0; k < roz*(roz+1)*2; k++){
		cin >> a >> b >> c >> d >> e;
		if(a == c)
			odl[a+1][b+1].up = e;
		else
			odl[a+1][b+1].right = e;
	}

	roz++;
	for(int i = 1; i <= roz; i++){
		for(int k = 1; k <= roz; k++){
			wyn[i][k] = min(wyn[i-1][k]+odl[i-1][k].right, wyn[i][k-1]+odl[i][k-1].up);
			if(wyn[i-1][k]+odl[i-1][k].right < wyn[i][k-1]+odl[i][k-1].up){
				wyn[i][k] = wyn[i-1][k]+odl[i-1][k].right;
				kier[i][k] = true;
			}
			else{
				wyn[i][k] = wyn[i][k-1]+odl[i][k-1].up;
			}
		}
	}
	wyn[0][1] = INT_MAX;

	cin >> a >> b >> energia;
	a++;
	b++;
    if(wyn[a][b] > energia)
        cout << "NIE";
    else{
        cout << energia - wyn[a][b] << endl;
            st.push({a-1,b-1});
	while(a > 1 || b > 1){
		if(kier[a][b])
			a--;
		else
			b--;
		st.push({a-1,b-1});
	}
    while(st.size() > 0){
        cout << st.top().first << "," << st.top().second << " ";
        st.pop();
    }
    }


  return 0;
}