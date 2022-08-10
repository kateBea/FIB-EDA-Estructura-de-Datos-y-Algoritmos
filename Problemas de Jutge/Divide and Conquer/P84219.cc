//FIRST OCURRENCE P84219

#include <iostream>
#include <vector>
using namespace std;

/*returns the first position of x in the vector v*/
int i_first_ocurrence(double x, const vector<double>& v, int e, int d)
{
    if (e > d) return -1;
    int m = (e+d)/2;
    if (x < v[m]) return i_first_ocurrence(x, v, e, m-1);
    if(x > v[m]) return i_first_ocurrence(x, v, m+1, d);
    if (m-1 >= e and v[m-1] == x) return i_first_ocurrence(x, v, e, m-1);
    return (v[m] == x) ? m : -1;
}

/*returns the first position of x in the vector v*/
int first_occurrence(double x, const vector<double>& v)
{
    return i_first_ocurrence(x, v, 0, (int)v.size()-1);
}

int main(int, char**)
{
    int n;
    std::cout << "Enter amount of elements: "; std::cin >> n;
    std::vector<double> v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    std::cout << "\nEnter element you're looking for: ";
    double x; std::cin >> x;
    std::cout << first_occurrence(x, v) << std::endl;

    return EXIT_SUCCESS;
}