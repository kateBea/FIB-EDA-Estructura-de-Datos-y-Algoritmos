//TWO COLORS        P29033

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>>  Grafo;

bool colorear(const Grafo& g, int u, int color, vector<int>& col) {
	if (col[u] == -1) { //no pintado
		col[u] = color;
		bool coloreable = true;
		for (int i = 0; i < g[u].size() and coloreable; ++i) {
			int v = g[u][i];
			coloreable = colorear(g, v, 1-color, col);
		}
		return coloreable;
	}
	else return (col[u] == color);
}

bool dos_color(const Grafo& g) {
	int n = g.size();
	vector<int> col(n, -1); //-1 sin color, 0 color, 1 color
	bool color = true;
	for (int i = 0; i < n and color; ++i) { //no es conexo
		if (col[i] == -1) 
			color = colorear(g, i, 0, col);
	}
	return color;
}

int main() {
	int n, m;
	
	while (cin >> n >> m) {
		Grafo g(n);
		
		int x, y;
		for (int i = 0; i < m; ++i) {
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		
		if (dos_color(g)) cout << "yes" << endl;
		else cout << "no" << endl;
		
		//cout << (dos_color(g) ? "yes" : "no") << endl;
	}
}