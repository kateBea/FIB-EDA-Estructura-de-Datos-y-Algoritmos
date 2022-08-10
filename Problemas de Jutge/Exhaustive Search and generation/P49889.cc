//CONSONANTS AND VOWELS     P49889

#include <iostream>
#include <vector>

/*print a complete solution from letter permutations*/
std::ostream& operator<<(std::ostream& _cout, const std::vector<char>& out)
{
    for (const auto& it : out) _cout << it;
    return _cout;
}

/*true if letter can be placed at pos level, false otherwise*/
bool can_be_placed(int level, unsigned int i, const std::vector<char>& lt, const std::vector<char>& out)
{
    /*every letter can be used once only in the entiure word*/
    for (int j = 0; j < level; ++j)
        if (out[j] == lt[i]) return false;

    /*check for alternance, consonant after vowel and viceversa*/
    if (level > 0 and level%2 == 0 and i%2 == 1) return false; //trying to put vowel instead of cons
    if (level > 0 and level%2 == 1 and i%2 == 0) return false; //trying to put consonant instead of vow

    /*NOTE: remember consonants are stored at even positions and vowels at odd pos*/
    return true;
}

/*compute letter permutations*/
void letter_perm(const std::vector<char>& lt, std::vector<char>& out, int level)
{
    if (level == (int)out.size()) std::cout << out << std::endl;
    else 
    {
        for (unsigned int i = 0; i < lt.size(); ++i)
        {
            if (can_be_placed(level, i, lt, out))
            {
                out[level] = lt[i];
                letter_perm(lt, out, level+1);
            }
        }
    }
}

int main(int, char**)
{
    int n_letters;
    std::vector<char> letters;
    std::vector<char> output;

    std::cin >> n_letters;
    letters = std::vector<char>(2*n_letters);
    output  = std::vector<char>(2*n_letters);      

    /*consonants at even positions, letters at odd positions*/
    for (int i = 0; i < 2*n_letters; i+=2) std::cin >> letters[i];
    for (int i = 1; i < 2*n_letters; i+=2) std::cin >> letters[i];

    letter_perm(letters, output, 0);


    return EXIT_SUCCESS;
}