//FOREST        X41530

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<int>> Grafo;

bool hay_ciclo(const Grafo& g, int i, vector<bool>& vis) {
	stack<pair<int, int>> P;
	P.push({i, -1});
	
	while (not P.empty()) {
		int u = P.top().first;
		int ant = P.top().second;
		P.pop();
		if (not vis[u]) {
			vis[u] = true;
			for (int v: g[u]) //for (int i = 0; i < g[u].size(); ++i) int v = g[u][i];
				if (not vis[v])P.push({v, u});
				else if (v != ant) return true;
		}
	}
	return false;
}

int dfs(const Grafo& g) {
	int n = g.size();
	vector<bool> vis(n, false);
	bool ciclo = false;
	int narb = 0;
	
	for (int i = 0; i < n and not ciclo; ++i) {
		if (not vis[i]) {
			if (hay_ciclo(g, i, vis)) ciclo = true;
			else ++narb;
		}
	}
	if (ciclo) narb = -1;
	return narb;
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
		
		int narb = dfs(g);
		if (narb == -1) cout << "no" << endl;
		else cout << narb << endl;
	}
}