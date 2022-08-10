//PAINTING A BOARD

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef pair<int,int> Pos;

const int X[4] = {-1, 0, 1, 0};
const int Y[4] = {0, 1, 0, -1};

void dfs_pintar(Tablero& t, int i, int j, char c) {
	stack<Pos> P;
	P.push({i, j});
	
	while (not P.empty()) {
		Pos act = P.top();
		P.pop();
		for (int k = 0; k < 4; ++k) {
			int x = act.first + X[k];
			int y = act.second + Y[k];
			if (t[x][y] == '.') {
				t[x][y] = c;
				P.push({x, y});
			}
		}
	}
}

void pintar_tablero(Tablero& t, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (t[i][j] != '#' and t[i][j] != '.') 
				dfs_pintar(t, i, j, t[i][j]);
		}
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		Tablero t(n, vector<char>(m));
		//leer tablero
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) cin >> t[i][j];
		}
		
		pintar_tablero(t, n, m);
		
		//escribir tablero pintado
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) cout << t[i][j];
			cout << endl;
		}
		cout << endl;
	}
}