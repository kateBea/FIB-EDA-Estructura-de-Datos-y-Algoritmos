//STATISTICAL MEASURES - P59282

#include <iostream>
#include <map>

void print_values(int min, int max, float avg)
{
    std::cout << "minimum: " << min << ", maximum: " << max << ", average: ";

    //fixed amount of decimals for output
    std::cout.setf(std::ios::fixed);
    std::cout.precision(4);
    std::cout << avg << std::endl;
    
}

int main()
{   
    //firs component represents the number
    //second component represents its number of occurences
    std::map<int, int> list_inputs;
    int total_sum = 0;
    float average = 0;
    int total_elements = 0;

    //NOTE: average is computed as: (X1*x + X2*y + X3*z...Xn*m)/n
    //x,y,z...m represent the occurences of the terms they're multiplying

    std::string opCode;
    while (std::cin >> opCode) 
    {
        if (opCode == "number")
        {
            int user_input;
            std::cin >> user_input;
            list_inputs[user_input]+=1;
            total_sum = total_sum+user_input;
            total_elements =total_elements+1;

            //after adding elements we recompute the average
            average=double(total_sum)/double(total_elements);
            std::map<int, int>::iterator it = list_inputs.end();
            it--;
            print_values(list_inputs.begin()->first, it->first, average);

        }
        else {
            if(list_inputs.empty()) std::cout << "no elements" << std::endl;
            else 
            {
                std::map<int, int>::iterator it = list_inputs.begin();
                it->second -=1;
                total_sum = total_sum-it->first;
                total_elements =total_elements-1;
                if (list_inputs.begin()->second == 0)
                list_inputs.erase(list_inputs.begin());

                //after deleting elements (or one instance of it) we recompute the average
                if (not list_inputs.empty()) 
                {
                    average=double(total_sum)/double(total_elements);
                    it = list_inputs.end();
                    it--;
                    print_values(list_inputs.begin()->first, it->first, average);
                }
                else std::cout << "no elements" << std::endl;
            }
        }
    }
}