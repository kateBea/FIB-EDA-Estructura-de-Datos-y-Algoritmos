//TREASIRES IN A MAP(1)     P70690

#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> row;
typedef vector<row> board;

typedef vector<bool> row_pos;
typedef vector<row_pos> boardCheck;

void look_for_treasure(const board& brd, boardCheck& _brd, int pos_x, int pos_y, bool& fnd)
{
    if (not _brd[pos_x][pos_y] and not fnd) {
        _brd[pos_x][pos_y] = true;
        if (brd[pos_x][pos_y] == 't') fnd = true;
        else if (brd[pos_x][pos_y] != 'X') {
            if (pos_y < int (brd[0].size()-1)) look_for_treasure(brd, _brd, pos_x, pos_y+1, fnd);
            if (pos_x < int (brd.size()-1)) look_for_treasure(brd, _brd, pos_x+1, pos_y, fnd);
            if (pos_y > 0) look_for_treasure(brd, _brd, pos_x, pos_y-1, fnd);
            if (pos_x > 0) look_for_treasure(brd, _brd, pos_x-1, pos_y, fnd);
        }
    }
}

int main()
{
    int n; //number rows
    int m; //number columns
    cin >> n >> m;
    board my_map(n, row(m));
    boardCheck mapCheck(n, row_pos(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> my_map[i][j];
    }

    //starting position 0 < r <= n, 0 < c <= m (r = row and c = col)
    int r, c; 
    cin >> r >> c;
    bool found_treasure = false;

    look_for_treasure(my_map, mapCheck, r-1, c-1, found_treasure);


    if (found_treasure) cout << "yes" << endl;
    else cout << "no" << endl;
}