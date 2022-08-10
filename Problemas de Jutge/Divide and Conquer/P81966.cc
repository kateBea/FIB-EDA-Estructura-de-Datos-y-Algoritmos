//DICOTOMIC SEARCH P81966

#include <iostream>
#include <vector>
using namespace std;

int position(double x, const vector<double>& v, int left, int right) {
    if (left > right) return -1;
    int pos = (left+right)/2;
    if (x < v[pos]) return position(x, v, left, pos-1);
    else if (x > v[pos]) return position(x, v, pos+1, right);
    else return pos;
}

typedef vector<double> Reals;

int main() {
    int n;
    cin >> n;
    Reals number(n);
    for (int i = 0; i < n; ++i) cin >> number[i];
    double y;
    cout << "Enter number to search: ";
    cin >> y;
    cout << position(y, number, 0, n-1) << endl;
}