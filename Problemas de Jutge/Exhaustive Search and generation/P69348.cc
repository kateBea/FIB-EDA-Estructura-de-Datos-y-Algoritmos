//FROM ONE TO N     P69348

#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& _cout, const std::vector<int>& out)
{
    int size = out.size();
    std::cout << '(';
    for (int i = 0; i < size; ++i)
    {
        if (i < size - 1)   std::cout << out[i] << ',';
        else                std::cout << out[i];
    }
    std::cout << ')';
    return _cout;
}

/**/
void n_permutations(std::vector<int>& perm, std::vector<bool>& used, int level)
{  
    if (level == int (perm.size())) std::cout << perm << std::endl;
    else
    {
        for (unsigned int i = 0; i < used.size(); ++i)
        {
            if (not used[i])
            {
                used[i] = true;
                perm[level] = i + 1;
                n_permutations(perm, used, level+1);
                used[i] = false;
            }
        }
    }

}

int main(int, char**)
{
    int                 user_input;
    std::vector<int>    permutation;
    std::vector<bool>   used_vals;

    std::cin    >>  user_input;
    permutation =   std::vector<int>  (user_input);
    used_vals   =   std::vector<bool> (user_input, false);

    n_permutations(permutation, used_vals, 0);
    return EXIT_SUCCESS;
}