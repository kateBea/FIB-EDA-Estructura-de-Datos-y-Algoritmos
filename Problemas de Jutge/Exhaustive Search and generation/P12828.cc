// ZEROS AND ONES (1)        P12828
#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& _cout, const std::vector<int>& out)
{
    for (unsigned int i = 0; i < out.size(); ++i)
    {
        if (i < out.size()-1)   _cout << out[i] << ' ';
        else                    _cout << out[i]; 
    }
    return _cout;
}

void exh_zerones(std::vector<int>& used, int level)
{
    if (level == int(used.size())) 
        std::cout << used << std::endl;
    else 
    {
        used[level] = 0; exh_zerones(used, level+1);
        used[level] = 1; exh_zerones(used, level+1);
    }
}

int main(int, char**)
{
    int user_input;
    std::vector<int> used;

    std::cin >> user_input;
    used = std::vector<int> (user_input);
    exh_zerones(used, 0);
    return 0;
}
