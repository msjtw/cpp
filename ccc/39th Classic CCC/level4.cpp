#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Direction {
	int x;
	int y;

	void turn_right() {
		if (x == 0 && y == -1) {
			x = 1;
			y = 0;
		} else if (x == 0 && y == 1) {
			x = -1;
			y = 0;
		} else if (x == 1 && y == 0) {
			x = 0;
            y = 1;
		} else {
			x = 0;
			y = -1;
		}
	}
	void turn_left() {
		if (x == 0 && y == -1) {
			x = -1;
			y = 0;
		} else if (x == 0 && y == 1) {
			x = 1;
			y = 0;
		} else if (x == 1 && y == 0) {
			x = 0;
            y = -1;
		} else {
			x = 0;
			y = 1;
		}
	}

	void move(int &x_, int &y_, vector<vector<int>> &vec ) {
        x_ += x;
		y_ += y;
		vec[y_][x_] = 1;
	}
	bool next_move_valid(int x_, int y_, vector<vector<int>> &vec) {
		x_ += x;
		y_ += y;
		int height = vec.size(), width = vec[0].size();
		if (x_ < 0 || y_ < 0 || x_ >= width || y_ >= height)
			return false;
		return vec[y_][x_] == 0;
	}

	char give_move() {
		if (x == 0 && y == -1) {
			return 'W';
		} else if (x == 0 && y == 1) {
			return 'S';
		} else if (x == 1 && y == 0) {
			return 'D';
		}
		return 'A';
	}
};


string pp(int xx, int xy, vector<vector<int>> &vec) {
	int height = vec.size(), width = vec[0].size();
	
	Direction dir = {1, 0};
	int x = xx, y = xy;
	string res;
	res += dir.give_move();
	dir.move(x, y, vec);

	while (dir.next_move_valid(x, y, vec)) {
		res += dir.give_move();
        dir.move(x, y, vec);
	}
	// w dół
	dir.turn_right();

	while (x != xx - 1) {
		while (dir.next_move_valid(x, y, vec)) {
			res += dir.give_move();
			dir.move(x, y, vec);
		}
		dir.turn_right();
		res += dir.give_move();
		dir.move(x, y, vec);
		if (x == xx -1) {
			break;
		}
		dir.turn_right();
		while (dir.next_move_valid(x, y, vec)) {
			res += dir.give_move();
			dir.move(x, y, vec);
		}
		dir.turn_left();
		res += dir.give_move();
		dir.move(x, y, vec);
		dir.turn_left();
	}

	// dzida w lewo
	while (dir.next_move_valid(x, y, vec)) {
		res += dir.give_move();
        dir.move(x, y, vec);
	}

	dir.turn_right();
	// dzida w górę
	while (dir.next_move_valid(x, y, vec)) {
		res += dir.give_move();
        dir.move(x, y, vec);
	}

	dir.turn_right();
	while (y != xy) {
		// dzida w prawo
		while (dir.next_move_valid(x, y, vec)) {
			res += dir.give_move();
			dir.move(x, y, vec);
		}
		// obrót
		dir.turn_right();
		res += dir.give_move();
		dir.move(x, y, vec);
		dir.turn_right();
		// dzida w lewo
		while (dir.next_move_valid(x, y, vec)) {
			res += dir.give_move();
			dir.move(x, y, vec);
		}
		dir.turn_left();
		res += dir.give_move();
		dir.move(x, y, vec);
		if (y == xy) {
			break;
		}
		dir.turn_left();
	}

	while (dir.next_move_valid(x, y, vec)) {
		while (dir.next_move_valid(x, y, vec)) {
			res += dir.give_move();
			dir.move(x, y, vec);
		}
		dir.turn_left();
	}
	return res;
}

string np(int xx, int xy, vector<vector<int>> &vec) {
	int height = vec.size(), width = vec[0].size();
	
	Direction dir = {1, 0};
	int x = xx, y = xy;
	string res;
	res += dir.give_move();
	dir.move(x, y, vec);

	while (dir.next_move_valid(x, y, vec)) {
		res += dir.give_move();
        dir.move(x, y, vec);
	}
	// w dół
	dir.turn_right();

	while (x != xx - 1) {
		while (dir.next_move_valid(x, y, vec)) {
			res += dir.give_move();
			dir.move(x, y, vec);
		}
		dir.turn_right();
		res += dir.give_move();
		dir.move(x, y, vec);
		if (x == xx -1) {
			break;
		}
		dir.turn_right();
		while (dir.next_move_valid(x, y, vec)) {
			res += dir.give_move();
			dir.move(x, y, vec);
		}
		dir.turn_left();
		res += dir.give_move();
		dir.move(x, y, vec);
		dir.turn_left();
	}

	// dzida w lewo
	while (dir.next_move_valid(x, y, vec)) {
		res += dir.give_move();
        dir.move(x, y, vec);
	}

	dir.turn_right();
	// dzida w górę
	while (dir.next_move_valid(x, y, vec)) {
		res += dir.give_move();
        dir.move(x, y, vec);
	}

	// dzida w prawo
	dir.turn_right();
	while (dir.next_move_valid(x, y, vec)) {
		res += dir.give_move();
        dir.move(x, y, vec);
	}

	dir.turn_right();
	while (y != xy && dir.next_move_valid(x, y, vec)) {
		// dzida w dół
		while (dir.next_move_valid(x, y, vec) && y + 1 != xy) {
			res += dir.give_move();
			dir.move(x, y, vec);
		}
		if (x - 1 == 0) {
			break;
		}
		// obrót
		dir.turn_right();
		if (dir.next_move_valid(x, y, vec)) {
			res += dir.give_move();
			dir.move(x, y, vec);
		}
		dir.turn_right();
		// dzida w górę
		while (dir.next_move_valid(x, y, vec)) {
			res += dir.give_move();
			dir.move(x, y, vec);
		}
		dir.turn_left();
		if (dir.next_move_valid(x, y, vec)) {
			res += dir.give_move();
			dir.move(x, y, vec);
		}
		if (y == xy) {
			break;
		}
		dir.turn_left();
	}

	while (dir.next_move_valid(x, y, vec)) {
		while (dir.next_move_valid(x, y, vec)) {
			res += dir.give_move();
			dir.move(x, y, vec);
		}
		dir.turn_left();
	}
	return res;
}

string nn(int xx, int xy, vector<vector<int>> &vec){
	bool flip = false;
	vector<vector<int>> flipniented;
	string ret;
	int x = xx, y = xy;
	int height = vec.size();
	int width = vec[0].size();

	//krok w góre
	Direction dir = {0, -1};
	dir.move(x,y,vec);
	ret += dir.give_move();

	//prawo w ściane
	dir.turn_right();
	while(dir.next_move_valid(x,y,vec)){
		dir.move(x,y,vec);
		ret += dir.give_move();
	}
	//w dół w podłogę
	dir.turn_right();
	while(dir.next_move_valid(x,y,vec)){
		dir.move(x,y,vec);
		ret += dir.give_move();
	}
	//mały zygzak mcqueen
	while(true){
		dir.turn_right();
		dir.move(x,y,vec);
		ret += dir.give_move();
		dir.turn_right();
		while(dir.next_move_valid(x,y,vec)){
			dir.move(x,y,vec);
			ret += dir.give_move();
		}
		dir.turn_left();
		dir.move(x,y,vec);
		ret += dir.give_move();
		dir.turn_left();
		while(dir.next_move_valid(x,y,vec)){
			dir.move(x,y,vec);
			ret += dir.give_move();
		}
		if(x-1 == xx){
			break;
		}
	}
	dir.turn_right();
	// rura po zygzaku do ściany
	while(dir.next_move_valid(x,y,vec)){
		dir.move(x,y,vec);
		ret += dir.give_move();
	}
	dir.turn_right();
	while(dir.next_move_valid(x,y,vec)){
		//od ściany do góry
		dir.move(x,y,vec);
		ret += dir.give_move();
		dir.turn_right();
		//dzida do środaka
		while(dir.next_move_valid(x,y,vec)){
			dir.move(x,y,vec);
			ret += dir.give_move();
		}
		// lepiej 3 razy w lewo niz raz w prawo
		// ojciec góra v2
		dir.turn_left();
		if(!dir.next_move_valid(x,y,vec))
			break;
		dir.move(x,y,vec);
		ret += dir.give_move();
		dir.turn_left();
		// dzida ściana
		while(dir.next_move_valid(x,y,vec)){
			dir.move(x,y,vec);
			ret += dir.give_move();
		}
		// ojciec góra
		dir.turn_right();
		//dzida w sciane od początku
	}

	return ret;
}
void flip(vector<vector<int>> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		reverse(vec[i].begin(), vec[i].end());
	}
}

int main() {
	int n;
	cin >> n;

	while (n--) {
		int width, height;
		cin >> width >> height;

		vector<vector<int>> grid(height, vector<int>(width));
		string s;
		int pos_x, pos_y;
		for (int j = 0; j < height; j++) {
			cin >> s;
			for (int i = 0; i < width; i++) {
			    if (s[i] == 'X') {
					pos_x = i;
					pos_y = j;
					grid[j][i] = 1;
				}
			}
		}

		// parzyste
		if (pos_x % 2 == 0 && pos_y % 2 == 0 && width % 2 == 1 && height % 2 == 1)
			cout << pp(pos_x, pos_y, grid) << endl;
		else if (pos_x % 2 == 1 && width % 2 == 1)
			cout << nn(pos_x, pos_y, grid) << endl;
		// nieparzyste/parzyste
		else if (pos_x % 2 == 1 && width % 2 == 0) {
			cout << np(pos_x, pos_y, grid) << endl;
		}
		// nieparzyste/parzyste do flipa
		else if (pos_x % 2 == 0 && width % 2 == 0) {
            flip(grid);
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (grid[i][j] == 1) {
						pos_y = i;
						pos_x = j;
					}
				}
			}
	        string res = np(pos_x, pos_y, grid);
			for (auto &it : res) {
				if (it == 'D')
					it = 'A';
				else if (it == 'A')
					it = 'D';
			}
			cout << res << endl;
		}
		// nieparzyste/parzyste do tranposa
		else if (pos_y % 2 == 1 && height % 2 == 0) {
            vector<vector<int>> new_grid(width, vector<int>(height));

			int new_pos_y = width - pos_x - 1;
			int new_pos_x = pos_y;

			new_grid[new_pos_y][new_pos_x] = 1;
			string res = np(new_pos_x, new_pos_y, new_grid);
			for (auto &it : res) {
				if (it == 'W') {
					it = 'D';
				}
				else if (it == 'D') {
					it = 'S';
				}
				else if (it == 'S') {
					it = 'A';
				}
				else if (it == 'A') {
					it = 'W';
				}
			}
			cout << res << endl;
		}
		else if (pos_y % 2 == 0 && height % 2 == 0) {
            vector<vector<int>> new_grid(width, vector<int>(height));

			int new_pos_x = height - pos_y - 1;
			int new_pos_y = pos_x;

			new_grid[new_pos_y][new_pos_x] = 1;
			string res = np(new_pos_x, new_pos_y, new_grid);
			for (auto &it : res) {
				if (it == 'W') {
					it = 'A';
				}
				else if (it == 'D') {
					it = 'W';
				}
				else if (it == 'S') {
					it = 'D';
				}
				else if (it == 'A') {
					it = 'S';
				}
			}
			cout << res << endl;
		}
	}
}
