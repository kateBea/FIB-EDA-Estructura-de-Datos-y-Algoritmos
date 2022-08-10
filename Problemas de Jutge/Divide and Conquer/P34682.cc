//FIXED POINTS P34682
#include <iostream>
#include <vector>

// Fa (i) = Xi + a
// i = Xi + a => Xi = i - a  

//look for target in vect (return index of first apparition if found)
//return -1 if target not found. vect is sorted increasingly
int find_fix_point(const std::vector<int>& vect, int left, int right, int target)
{
    if (left > right) return -1;
    int midle = (left+right)/2;
    if (vect[midle] > (midle+1) - target) return find_fix_point(vect, left, midle-1, target);
    if (vect[midle] < (midle+1) - target) return find_fix_point(vect, midle+1, right, target);

    int ret = find_fix_point(vect, left, midle-1, target);   
    if (ret == -1) return midle;
    else return ret; 
}

int main()
{
    int sequence_lenght;
    int seq_number = 1;
    bool first = true;

    while (std::cin >> sequence_lenght)
    {
        std::cout << "Sequence #" << seq_number++ << std::endl;
        std::vector<int> seq(sequence_lenght);
        for (int i = 0; i < sequence_lenght; ++i) std::cin >> seq[i];

        int amount_indices; std::cin >> amount_indices;
        for (int i = 0; i < amount_indices; ++i) 
        {
            /*NOTE: index might be confusing*/
            /*index is equal to a in this implementation, see line 6*/
            int index; std::cin >> index;
            int result = find_fix_point(seq, 0, (int)seq.size()-1, index);
            if (result == -1) std::cout << "no fixed point for " << index << std::endl;
            else              std::cout << "fixed point for " << index << ": " << result+1 << std::endl;
        }

        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}