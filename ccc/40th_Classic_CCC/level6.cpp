#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	while (n --> 0) {
		int x, y, maximum, len;
		cin >> x >> y >> maximum >> len;
		vector<vector<char>> vec(y, vector<char>(x, '.'));
        if(len == 1){
            for(int i = 0; i < y; i+=2){
                for(int k = 0; k < x; k += 2){
                    vec[i][k] = 'X';
                }
            }
        }
        if(len == 3){
            int maxj = 0;
            for (int i = 0; i < y; i += 2) {
                for (int j = 0; j < x - 2; j += 4) {
                    vec[i][j] = 'X';
                    vec[i][j + 1] = 'X';
                    vec[i][j + 2] = 'X';
                    maxj = max(maxj, j + 2);
                }
            }
            for (int j = maxj + 2; j < x; j += 2) {
                for (int i = 0; i < y - 2; i += 4) {
                    vec[i][j] = 'X';
                    vec[i + 1][j] = 'X';
                    vec[i + 2][j] = 'X';
                }
            }
        }
        if(len == 5){
            int maxj = 0;
            for(int i = 0; i < y; i+= 2){
                for(int j = 0; j < x - 4; j += 6){
                    vec[i][j] = 'X';
                    vec[i][j + 1] = 'X';
                    vec[i][j + 2] = 'X';
                    vec[i][j + 3] = 'X';
                    vec[i][j + 4] = 'X';
                    maxj = max(maxj, j+4);
                }
            }
            for (int j = maxj + 2; j < x; j += 2) {
                for (int i = 0; i < y - 4; i += 6) {
                    vec[i][j] = 'X';
                    vec[i + 1][j] = 'X';
                    vec[i + 2][j] = 'X';
                    vec[i + 3][j] = 'X';
                    vec[i + 4][j] = 'X';
                }
            }
        }
		if(len == 7){
            int maxj = 0;
            for(int i = 0; i < y; i+= 2){
                for(int j = 0; j < x - 6; j += 8){
                    vec[i][j] = 'X';
                    vec[i][j + 1] = 'X';
                    vec[i][j + 2] = 'X';
                    vec[i][j + 3] = 'X';
                    vec[i][j + 4] = 'X';
                    vec[i][j + 5] = 'X';
                    vec[i][j + 6] = 'X';
                    maxj = max(maxj, j+6);
                }
            }
            for (int j = maxj + 2; j < x; j += 2) {
                for (int i = 0; i < y - 6; i += 8) {
                    vec[i][j] = 'X';
                    vec[i + 1][j] = 'X';
                    vec[i + 2][j] = 'X';
                    vec[i + 3][j] = 'X';
                    vec[i + 4][j] = 'X';
                    vec[i + 5][j] = 'X';
                    vec[i + 6][j] = 'X';
                }
            }
        }

		for (auto& row : vec) {
			for (auto& el : row) {
				cout << el;
			}
			cout << endl;
		}
		cout << endl;
	}


	return 0;
}
