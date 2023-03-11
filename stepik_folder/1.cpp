#include <iostream>
#include <map>
#include <vector>

int main() {
    std::map<int,std::vector<int>> numbers;
    int count = 0;
    std::cin >> count;
    for(int i = 0; i < count; i++)
    {
        int input;
        std::cin >> input;
        numbers[input].push_back(i);
    }

    for(auto [key, value]: numbers)
    {
        for(auto v: value)
        {
            std::cout << v << ' ';
        }
    }

    return 0;
}