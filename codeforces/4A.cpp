// https://codeforces.com/problemset/problem/4/A
#include <iostream>

int main()
{
    int weight = 0;
    std::cin >> weight;
    std::cout << (((weight > 2) && (weight % 2 == 0)) ? "YES" : "NO");
    return 0;
}