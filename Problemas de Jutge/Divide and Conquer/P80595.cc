//HOW MANY INVERSIONS P80595

#include <iostream>
#include <vector>

/*Counts inversions in vect and sorst vect increasingly*/
int i_inversions(std::vector<int>& vect, int left, int right)
{
    if (left >= right) return 0;
    int midle = (left+right)/2;

    /*count amount of inversions from both subarrays*/
    int left_count = i_inversions(vect, left, midle);
    int right_count = i_inversions(vect, midle+1, right);

    std::vector<int> aux((right-left)+1);
    int it_left     = left;
    int it_right    = midle + 1;
    int it_aux      = 0;

    int counter = 0;

    while (it_left <= midle and it_right <= right)
    {
        if (vect[it_left] <= vect[it_right])    aux[it_aux++] = vect[it_left++];
        else                                    {aux[it_aux++] = vect[it_right++]; counter+=(midle-it_left)+1;}
    }
    /*If vect[it_left] > vect[it_right] then we have (midle-it_left) elements at the moment of the sort*/
    /*which are greater than the other (midle-it_right)+1 elements*/

    while (it_left <= midle)    aux[it_aux++] = vect[it_left++];
    while (it_right <= right)   aux[it_aux++] = vect[it_right++];

    for (int it = 0; it < (right-left)+1; ++it) vect[it+left] = aux[it];

    /*the total amount of inversios is the sum between*/
    /*the inversions in left subarray and inversions in right subarray*/
    return counter+left_count+right_count;
}

/*Counts inversions in vect and sorst vect increasingly*/
int inversions(std::vector<int>& vect) 
{
    return i_inversions(vect, 0, (int)vect.size()-1);
}

int main()
{
    int user_input;

    while (std::cin >> user_input)
    {
        std::vector<int> storage(user_input);
        for (auto& value : storage) std::cin >> value;

        std::cout << inversions(storage) << std::endl;
    }
    return EXIT_SUCCESS;
}