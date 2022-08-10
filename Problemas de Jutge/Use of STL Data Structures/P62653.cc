//TICKET DISTRIBUTION  P62653
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define END_OF_EVENTS   "E" 
#define AVAIL_TICKET    "T"
#define ASK_TICKET      "S"

int main(int, char**)
{
    std::string event;
    std::string starting_word;
    std::string supporter_word;

    int available_tickets;

    /*lambda fucntion for to sort priority queue containing supporters that ask for tickets*/
    auto comp = [&] (const std::string& _a, const std::string& _b) -> bool
    {
        if (_a.size() == _b.size())
        {
            std::string str_for_comp = starting_word.substr(0, _b.size());
            if (_a < str_for_comp and _b >= str_for_comp)   return true;
            if (_b < str_for_comp and _a >= str_for_comp)   return false;
            return _a > _b;
        }
        else return _a.size() > _b.size();
    };

    while (std::cin >> starting_word)
    {
        /*Contains all the supporters that ask for a ticket sorted accordingly*/
        std::priority_queue<std::string, std::vector<std::string>, decltype(comp)> tickets_asked(comp);

        std::cin >> event;
        available_tickets = 0;
        /*starting new set of events*/
        while (event != END_OF_EVENTS)
        {
            /*Ticket is available to offer*/
            if (event == AVAIL_TICKET) ++available_tickets;
            else 
            {
                /*Suporter asks for ticket*/
                std::cin >> supporter_word;
                tickets_asked.push(supporter_word);
            }
            
            /*distribute tickets*/
            for (;available_tickets and not tickets_asked.empty(); tickets_asked.pop(), --available_tickets)
                std::cout << tickets_asked.top() << std::endl;
            std::cin >> event;
        }

        /*set of events finished*/
        std::cout << available_tickets << " ticket(s) left" << std::endl;
        std::cout << tickets_asked.size() << " supporter(s) with no ticket" << std::endl;
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}