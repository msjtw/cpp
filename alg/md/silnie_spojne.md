## SCC
```c++
// zrodlo: https://www.youtube.com/watch?v=sdw2-7Cc9Q0&t=6208s

const int SIZE = 1000 + 7;
int wierz, drog; 
int kolor;

bool odw[SIZE];
int spojna[SIZE];
vector <int> graf[SIZE];
vector <int> farg[SIZE];

vector <int> kol;

void dfs(int x){
	odw[x] = true;
	for(int i = 0; i < (int)graf[x].size(); i++)
		if(!odw[graf[x][i]])
			dfs(graf[x][i]);
	kol.push_back(x);
}

void SCC2(int x, int kol){
	spojna[x] = kolor;
	for(int i = 0; i < (int)farg[x].size(); i++)
		if(spojna[farg[x][i]] == 0)
			SCC2(farg[x][i], kol);
}

void SCC(){
	for(int i = 1; i <= wierz; i++)
		if(!odw[i])
			dfs(i);
	for(int i = kol.size()-1; i >= 0; i--)
		if(spojna[kol[i]] == 0)
			SCC2(kol[i], ++kolor);
}
```