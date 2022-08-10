//COLLATZ PSEUDO-SEQUENCES (2) - P69781

#include <iostream>
#include <map>

const int LIMIT = 1e8;

//compute next value in Collatz sequence
//returns val/2 + _x if val is even
//returns val*3 + y if val is odd
int nextUpValue(int val, int _x, int _y)
{
	return val % 2 == 0 ? val / 2 + _x : 3 * val + _y;
}

int cycleLenght(int val, int _x, int _y)
{
	int result = 0;
	std::map<int, std::pair<int, int>> numbers;
	bool limitExceeded = val > LIMIT;
	bool cycleFound = false;
	int it = 1;
	while (not limitExceeded and not cycleFound) 
    {
		val = nextUpValue(val, _x, _y);
		if (val > LIMIT) {
			result = val;
			limitExceeded = true;
		}
		else 
        {
			auto iter = numbers.find(val);
			if (iter == numbers.end()) 
				//primera aparición dentro de la secuencia
				//guardamos la posiciones actual de it
				//y anotamos una aparicion para el numero en la secuencia
				numbers.insert(std::make_pair(val, std::make_pair(1, it)));
			else 
            {
				//segunda aparicion del numero
				iter->second.first++;
				if (iter->second.first <= 1) iter->second.second = it;
				else {
					cycleFound = true;
					result = iter->second.second - it;
				}
			}

			++it;
		}
	}

	return std::abs(result);
}

int main(void)
{
	int x, y, n; 
	while (std::cin >> x >> y >> n) 
    {
		std::cout << cycleLenght(n, x, y) << std::endl;
	}
	return 0;
}