//QUEENS(2)     P17921s

#include <iostream>
#include <vector>

class Queen
{
public:
    Queen() {}
    Queen(int n) : 
        m_Solutions(0), 
        m_Size(n),
        m_Sol(std::vector<int>(n)),
        m_Col(std::vector<bool> (n, false)),
        m_Main_diag(std::vector<bool>(2*n-1, false)),
        m_Second_diag(std::vector<bool>(2*n-1, false))
        {}
    
    /*position of m_Main_diag ocuppied by queen at row i, column j*/
    int main_diag_pos(int i, int j) {return (m_Size-j-1) + i;}

    /*posituion of m_Second_diag ocupied by queen at row i, column j*/
    int seco_diag_pos(int i, int j) {return i + j;}

     /*number of solutions*/
    unsigned int total() const {return m_Solutions;}

    /*solve queen problem*/
    void solve() 
    {
        bool found = false; 
        solve(0, found);
        if (not found) std::cout << "NO SOLUTION" << std::endl;
    }


private:
    /*print solution*/
    void print()
    {
        for (unsigned int i = 0; i < m_Size; ++i)
        {
            for (unsigned int j = 0; j < m_Size; ++j)
            {
                if (m_Sol[i] == int(j))  std::cout << 'Q';
                else                    std::cout << '.';
            }
            std::cout << std::endl;
        }
    }

    /*solve n-queen problem*/
    void solve(unsigned int level, bool& found)
    {
        if (level == m_Size and not found) 
        {
            found = true; 
            print();
        }
        else 
        {
            for (unsigned int col = 0; col < m_Size and not found; ++col)
            {
                bool q_col = m_Col[col];
                bool q_diag1 = m_Main_diag[main_diag_pos(level, col)];
                bool q_diag2 = m_Second_diag[seco_diag_pos(level, col)];
                if (not q_col and not q_diag1 and not q_diag2)
                {
                    m_Sol[level] = col;

                    m_Col[col] = true;
                    m_Main_diag[main_diag_pos(level, col)] = true;
                    m_Second_diag[seco_diag_pos(level, col)] = true;

                    solve(level + 1, found);

                    m_Col[col] = false;
                    m_Main_diag[main_diag_pos(level, col)] = false;
                    m_Second_diag[seco_diag_pos(level, col)] = false;
                }
            }
        }
    }

private:
    unsigned int        m_Solutions;    //total amount of solutions for given board size
    unsigned int        m_Size;         //size of the board
    std::vector<int>    m_Sol;          //store a possible solution
    std::vector<bool>   m_Col;          //true if theres queen at colum i ( 0 <= i < m_Col.size())
    std::vector<bool>   m_Main_diag;    //store quens at main diagonal
    std::vector<bool>   m_Second_diag;  //store queens at secondary diagonal
};

int main(int, char**)
{
    int user_input;
    std::cin >> user_input;
    Queen _queen(user_input);

    _queen.solve();

    return EXIT_SUCCESS;
}