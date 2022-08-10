//TREASURES IN A MAP(3)        P90766

#include <iostream>
#include <vector>
#include <queue>

#define TREASURE    't'
#define OBSTACLE    'X'
#define EMP_PATH    '.'

/*map with treasures*/
typedef std::vector<std::vector<char>> board;
typedef std::vector<std::vector<bool>> board_visited;

enum DIRECTION {UP, DOWN, LEFT, RIGHT};

struct pos 
{
    int x;  //fila
    int y;  //columna
    pos() : x(), y() {}
    pos(const pos& _pos) = default;
    pos(int _x, int _y) : x(_x), y(_y) {}

    pos& operator+=(DIRECTION dir)
    {
        switch(dir)
        {
            case UP: --x; break;
            case DOWN: ++x; break;
            case LEFT: --y; break;
            case RIGHT: ++y; break;
        }
        return *this;
    } 
    
    pos operator+(DIRECTION dir)
    {
        pos return_pos;
        return_pos.x = this->x;
        return_pos.y = this->y;
        switch(dir)
        {
            case UP:    return_pos.x--;     break;
            case DOWN:  return_pos.x++;     break;
            case LEFT:  return_pos.y--;     break;
            case RIGHT: return_pos.y ++;    break;
        }
        return return_pos;
    } 
};

/*return amount of reachable treasures starting form position (x,y)*/
int reachable_treasures(const board& _board, const pos& _start)
{
    int treasures;
    int rows;
    int columns;
    board_visited vis;
    std::queue<pos> next_on_line;

    rows = _board.size();
    columns = _board[0].size();
    vis = board_visited(rows, std::vector<bool> (columns, false));
    treasures = 0;
    next_on_line.push(_start);

    while (not next_on_line.empty())
    {
        pos temp = next_on_line.front();
        pos adjacent;
        next_on_line.pop();

        for (int i = 0; i < 4; ++i)
        {
            adjacent = temp + DIRECTION(i);
            bool temp1 = adjacent.x >= 0 and adjacent.x < rows;
            bool temp2 = adjacent.y >= 0 and adjacent.y < columns;
            bool pos_ok = temp1 and temp2;
            if (pos_ok and not vis[adjacent.x][adjacent.y])
            {
                vis[adjacent.x][adjacent.y] = true;
                if (not (_board[adjacent.x][adjacent.y] == OBSTACLE)) 
                    next_on_line.push(adjacent);
                if (_board[adjacent.x][adjacent.y] == TREASURE)
                    ++treasures;       
            }
        }
    }
    return treasures;
}

int main(int, char**)
{
    int n_rows;
    int m_cols;
    board my_board;

    /*read board*/
    std::cin >> n_rows >> m_cols;
    my_board = board(n_rows, std::vector<char>(m_cols));

    for (int i = 0; i < n_rows; ++i)
        for (int j = 0; j < m_cols; ++j)
            std::cin >> my_board[i][j];

    /*read the starting position*/
    int start_x;    
    int start_y;
    std::cin >> start_x >> start_y;

    /*print amount of reachable treasures*/
    std::cout << reachable_treasures(my_board, pos(start_x-1, start_y-1)) << std::endl;
    return EXIT_SUCCESS;
}