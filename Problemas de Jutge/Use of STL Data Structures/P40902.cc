//CASINO - P40902

#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> players;
    std::string operation;

    std::string name, opetarion;
    int amount;
    while (std::cin >> name >> operation) {
        if (operation == "enters") {
            //if player already exist throw and error. Add them otherwise
            if (players.find(name) != players.end()) std::cout 
            << name << " is already in the casino" << std::endl;
            else players.insert(make_pair(name, 0)); 
        }
        else if (operation == "leaves") {
            //if player does not exist throw an error. Erase them otherwise
            if (players.find(name) == players.end()) std::cout 
            << name << " is not in the casino" << std::endl;
            else {
                std::cout << name << " has won " << players[name] << std::endl;
                players.erase(name);
            }
        }
        else {
            std::cin >> amount;
            std::map<std::string, int>::iterator it = players.find(name);
            if (it == players.end()) std::cout << name << " is not in the casino" << std::endl;
            else players[name]+=amount;
        }
    }
    std::cout << "----------" << std::endl;
    for (std::map<std::string, int>::iterator it = players.begin(); it != players.end(); ++it) {
        std::cout << it->first << " is winning " << it->second << std::endl;
    }
}