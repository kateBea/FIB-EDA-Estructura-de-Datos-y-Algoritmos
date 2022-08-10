//K-TH ELEMENT - P63584

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int k_esim(int k, const VVI& V) {
	map<int, int> min;
	for (int i = 0; i < V.size(); ++i) {
		if (!V[i].empty()) min[V[i][0]] = i;
	}

	pair<int, int> res;
	VI it(V.size(), 1);

	while (k > 0) {
		res.first = min.begin()->first;
		res.second = min.begin()->second;
		if (V[res.second].size() > it[res.second]) {
			int aux = V[res.second][it[res.second]++];
			min[aux] = res.second;
		}
		min.erase(min.begin());
		--k;
	}
	return res.first;
}

int k_esimAlt(int k, const VVI& V)
{
	VI auxiliar = V[0];
	for (int i = 1; i < (int)V.size(); ++i) {
		for (int j : V[i]) {
			auxiliar.push_back(j); 
			int k = (int)auxiliar.size();
			while (--k > 0 and auxiliar[k] < auxiliar[k - 1])
				swap(auxiliar[k], auxiliar[k - 1]);
		}
	}
	return auxiliar[k - 1];
}

void read_elements(VVI& v)
{
	int n, m; std::cin >> n;
	v = VVI(n);
	for (VI& i : v) {
		std::cin >> m;
		i = VI(m);
		for (int& j : i) std::cin >> j;
	}
}

void print_elements(const VVI& v)
{
	int n = (int)v.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)v[i].size(); ++j)
			std::cout << v[i][j] << ' ';
		std::cout << endl;
	}
	std::cout << std::endl;
}

int main(void)
{
	VVI V1;
	read_elements(V1);
	print_elements(V1);
	int k_element; std::cin >> k_element;
	
	std::cout << k_element << "-th largest element : " << k_esim(k_element, V1);
}