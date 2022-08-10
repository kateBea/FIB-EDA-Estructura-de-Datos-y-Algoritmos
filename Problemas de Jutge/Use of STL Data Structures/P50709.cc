//COLLECTION OF NUMBERS - P50709

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    char user_input;
    while (cin >> user_input)
    {
        switch (user_input)
        {
        case 'S':
            int number;
            cin >> number;
            pq.push(number);
            break;

        case 'A':
            if (pq.empty())
                cout << "error!" << endl;
            else
                cout << pq.top() << endl;
            break;

        case 'R':
            if (pq.empty())
                cout << "error!" << endl;
            else
                pq.pop();
            break;

        case 'I':
            int units;
            cin >> units;
            if (pq.empty())
                cout << "error!" << endl;
            else
            {
                int save = pq.top();
                save += units;
                pq.pop();
                pq.push(save);
            }
            break;

        case 'D':
            cin >> units;
            if (pq.empty())
                cout << "error!" << endl;
            else
            {
                int save = pq.top();
                save -= units;
                pq.pop();
                pq.push(save);
            }
            break;

        default:
            break;
        }
    }
}