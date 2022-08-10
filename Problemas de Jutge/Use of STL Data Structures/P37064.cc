//DYNAMIC MEDIAN - P37064

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<string> bagOfWords;
    set<string>::iterator mid;
    auto it = bagOfWords.begin();
    string word;
    cin >> word;
    if (word != "END")
    {
        it = bagOfWords.insert(it, word);
        cout << word << endl;
        mid = bagOfWords.begin();
        while (cin >> word and word != "END")
        {
            bagOfWords.insert(it, word);
            if (word < *mid and bagOfWords.size() % 2 == 0)
                --mid;
            else if (word > *mid and bagOfWords.size() % 2 != 0)
                ++mid;
            cout << *mid << endl;
        }
    }
}
