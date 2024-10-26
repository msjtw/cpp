#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n --> 0) {
		int a, b, maximum;
		cin >> a >> b >> maximum;
        int id = 1;
		vector<vector<int>> vec(b, vector<int>(a));
        int vert = 0;
		for(int i = 0; i < b; i+=2){
            for(int k = 0; k < a; k+=4){
                if(k+3 <= a){
                    for(int z = k; z < k+3; z++){
                        vec[i][z] = 1;
                        vert = max(vert, z);
                    }
                }
            }
        }
        cout << vert << endl;
        for (auto& row : vec) {
			for (auto& el : row) {
				cout << el << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
