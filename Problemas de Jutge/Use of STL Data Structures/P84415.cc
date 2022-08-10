//BAG OF WORDS - P84415

#include <iostream>
#include <map>
using namespace std;

int main()
{
    string operation, word, user_input;
    map<string, int> bag_word;
    while (cin >> operation) {
        if(operation=="store") {
            cin >> user_input;
            bag_word[user_input]+=1;
        }
        else if(operation=="delete") {
            cin >> user_input;
            if (not bag_word.empty()) {
                map<string, int>::iterator it = bag_word.find(user_input);
                --it->second;
                if (it->second == 0) bag_word.erase(it);
            }
        }
        else {
            if (operation=="maximum?") {
                if (bag_word.empty()) cout << "indefinite maximum" << endl;
                else {
                    map<string, int>::iterator it = --bag_word.end();
                    cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
                }
            }
            else {
                if (bag_word.empty()) cout << "indefinite minimum" << endl;
                else {
                    map<string, int>::iterator it = bag_word.begin();
                    cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
                }
            }
        }
    }
}