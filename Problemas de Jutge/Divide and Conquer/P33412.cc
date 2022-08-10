//RESISTANT DICHOTOMIC SEARCH P33412

#include <iostream>
#include <vector>
using namespace std;

/*binarySarch returns the first position of x in the vector v*/
bool i_resistant_search(double x, const vector<double>& v, int e, int d)
{
    if (e > d) return false;
    int m = (e+d)/2;
    if (x == v[m]) return true;
    else if (x > v[m]) {
        if (m > e and x == v[m-1]) return true;
        return i_resistant_search(x, v, m+1, d);
    }
    else {
        if (m < d and x == v[m+1]) return true;
        return i_resistant_search(x, v, e, m-1);
    }
}

bool resistant_search(double x, const vector<double>& v)
{
    return i_resistant_search(x, v, 0, v.size()-1);
}