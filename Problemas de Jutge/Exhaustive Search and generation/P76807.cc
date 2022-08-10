//SUDOKU        P76807

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> MI;
typedef vector<MI> MMI;

void escriu(MI& M) {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
    	if (j != 0) cout << ' ';
		cout << M[i][j];
	}
    cout << endl;
  }
}

bool backtracking(int i, int j, MI& M, MI& fila, MI& colu, MMI& sudoku) {
  	if (i == 9) {
    	escriu(M);
    	return true;
  	}
  	else if (j == 9) return backtracking(i+1, 0, M, fila, colu, sudoku);
	else if (M[i][j] != 0) return backtracking(i, j+1, M, fila, colu, sudoku);
	else {
		for (int d = 1; d <= 9; ++d) {
    		if (not fila[i][d] and not colu[j][d] and not sudoku[i/3][j/3][d]) {
      			fila[i][d] = colu[j][d] = sudoku[i/3][j/3][d] = 1;
      			M[i][j] = d;
      			if (backtracking(i, j+1, M, fila, colu, sudoku)) return true;
      			M[i][j] = 0;
      			fila[i][d] = colu[j][d] = sudoku[i/3][j/3][d] = 0;
    		}
    	}
	}
  	return false;
}

int main() {
  	int n;
  	cin >> n;
  	cout << n << endl;
  	for (int i = 0; i < n; ++i){
    	cout << endl;
    
    	MI M(9, VI(9));
   	 	MI fila(9, VI(10, 0));
    	MI colu(9, VI(10, 0));
    	MMI sudoku(3, MI(3, VI(10, 0)));
    
    	for (int i = 0; i < 9; ++i)
      	for (int j = 0; j < 9; ++j) {
        	char c;
        	cin >> c;
        	if (c == '.') M[i][j] = 0;
        	else {
          		int d = c - '0';
          		M[i][j] = d;
          		fila[i][d] = colu[j][d] = sudoku[i/3][j/3][d] = 1;
        	}
    	}

    	backtracking(0, 0, M, fila, colu, sudoku);
  	}
}