//TREASURES IN A MAP(2)     P60796

#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define TREASURE    't'
#define OBSTACLE    'X'
#define EMP_PATH    '.'

/*graph definitions*/
typedef std::vector<char>               rows;
typedef std::vector<bool>               rows_check;
typedef std::vector<rows>               board;
typedef std::vector<rows_check>         board_check;
typedef std::vector<std::vector<bool>>  board_visited;
typedef std::vector<std::vector<int>>   board_dist;

/*for use on pos operations*/
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

/*minimum steps to reach a treasure*/
void min_steps(const board& _board, const pos& source)
{
    bool found; 
    pos target;
    board_dist distance;
    int _rows, _colums;
    std::queue<pos> next;
    board_check vis;

    _rows = _board.size();
    _colums = _board[0].size();
    distance = board_dist(_rows, std::vector<int>(_colums, 0));
    vis = board_check(_rows, std::vector<bool> (_colums, false));  

    next.push(source);
    vis[source.x][source.y] = true;

    while (not next.empty())
    {
        pos temp;
        pos adjacent;
        
        
        temp = next.front();
        next.pop();

        for (int i = 0; i < 4 and not found; ++i)
        {
            adjacent = temp + DIRECTION(i);
            bool temp1 = adjacent.x >= 0 and adjacent.x < _rows;
            bool temp2 = adjacent.y >= 0 and adjacent.y < _colums;
            bool pos_ok = temp1 and temp2;
            if (pos_ok and not vis[adjacent.x][adjacent.y])
            {
                vis[adjacent.x][adjacent.y] = true;
                distance[adjacent.x][adjacent.y] = 1 + distance[temp.x][temp.y];
                if (not (_board[adjacent.x][adjacent.y] == OBSTACLE)) 
                    next.push(adjacent);
                if (_board[adjacent.x][adjacent.y] == TREASURE)
                {
                    found = true;
                    target = adjacent;
                }     
            }
        }

        /*break loop if treasure found*/
        if (found) break;
    }

    if (found)  std::cout << "minimum distance: " << distance[target.x][target.y];
    else        std::cout << "no treasure can be reached" << std::endl;
}

int main(int, char**)
{
    int _rows, _columns;
    board _board;

    std::cin >> _rows >> _columns;
    _board = board(_rows, rows(_columns));

    for (auto& row : _board)
        for (auto& col : row) std::cin >> col;

    pos src;
    std::cin >> src.x >> src.y;
    src.x -= 1;
    src.y -= 1;
    min_steps(_board, src);

    return EXIT_SUCCESS;    
}