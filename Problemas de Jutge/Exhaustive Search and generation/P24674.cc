//PERMUTATION OF WORDS      P24674

#include <iostream>
#include <vector>
#include <list>

typedef std::vector<std::string>    word_list;
typedef std::vector<bool>           used_word;

std::ostream& operator<<(std::ostream& _cout, const std::vector<std::string>& out)
{   
    std::cout << '(';
    for (unsigned int i = 0; i < out.size(); ++i)
    {
        if (i < out.size() - 1) std::cout << out[i] << ',';
        else                    std::cout << out[i];
    }
    std::cout << ')';
    return _cout;   
}

void word_perm(const word_list& _words, used_word& used, std::vector<std::string>& out, int level)
{
    if (level == int (_words.size())) std::cout << out << std::endl;
    else 
    {
        for (unsigned int it = 0; it < _words.size(); ++it)
        {
            if (not used[it])
            {
                used[it] = true;
                out.push_back(_words[it]);
                word_perm(_words, used, out, level+1);
                used[it] = false;
                out.pop_back();
            }
        }
    }
}

int main(int, char**)
{
    int sequence_lenght;
    std::vector<std::string> out;
    word_list words;
    used_word used;

    std::cin >> sequence_lenght;
    words = word_list(sequence_lenght);
    used = used_word(sequence_lenght, false);
    for (auto& word : words) std::cin >> word;

    word_perm(words, used, out, 0);

    return EXIT_SUCCESS;
}
