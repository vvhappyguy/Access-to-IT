// https://codeforces.com/problemset/problem/71/A
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int count = 0;
    std::cin >> count;
    std::vector<std::string> words;
    for (int i = 0; i < count; ++i)
    {
        std::string word;
        std::cin >> word;
        if (word.size() <= 10)
        {
            words.push_back(word);
        }
        else
        {
            std::string long_word = word[0] + std::to_string(word.size() - 2) + word[word.size() - 1];
            words.push_back(long_word);
        }
    }
    for (const auto& word : words)
        std::cout << word << std::endl;
    return 0;
}