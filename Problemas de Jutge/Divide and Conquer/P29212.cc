// MODULAR EXPONENTIATION P29212

#include <iostream>
#include <vector>
using namespace std;

int fastExpo(int base, int exponent, int mod)
{
    if (exponent == 0) return 1;
    int product = fastExpo(base, exponent / 2, mod);

    if (exponent % 2 == 0)  return (product * product % mod);
    else                    return (product * product % mod) * base % mod;
}

int main(void)
{
    int nNum; 
    int kNum; 
    int mNum;

    while (std::cin >> nNum >> kNum >> mNum)
    {
        std::cout << fastExpo(nNum, kNum, mNum) % mNum << std::endl;
    }

    return EXIT_SUCCESS;
}