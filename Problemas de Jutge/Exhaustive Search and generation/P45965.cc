//ZEROS AND ONES (2)        P45965

#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& _cout, const std::vector<int>& out)
{
    for (int i = 0; i < (int)out.size(); ++i)
    {
        if (i < int(out.size() - 1))    std::cout << out[i] << ' ';
        else                            std::cout << out[i];
    }
    return _cout;
}

/*binary sequnce with exactly k ones*/
void binary_k_ones(std::vector<int>& bin, int curr_ones, int curr_zeros, int k, int level)
{
    if (level == int (bin.size())) std::cout << bin << std::endl;
    else 
    {
        if (curr_zeros < (int)bin.size() - k) 
        {
            //si no me queda espacio poara meter suficientes unos para llegar a k unos
            bin[level] = 0; 
            binary_k_ones(bin, curr_ones, curr_zeros+1, k, level+1);
        }
        if (curr_ones < k)
        {
            //si no llevo mas unos de los necesario
            bin[level] = 1; 
            binary_k_ones(bin, curr_ones+1, curr_zeros, k, level+1);
        }
    }
}

int main(int, char**)
{
    int seq_lenght;
    int max_ones;
    std::vector<int> binary;
    
    std::cin >> seq_lenght >> max_ones;
    binary = std::vector<int>(seq_lenght);
    binary_k_ones(binary, 0, 0, max_ones, 0);
    return EXIT_SUCCESS;
}