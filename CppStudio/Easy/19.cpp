// compiled with clang (10.0.1)
// 19. Программа палиндром в С++
// Input: string
// Output: string

#include <iostream>
#include <string>
using namespace std;

bool palindr(string word)
{
    if (word.length() == 1 || word.length() == 0)
        return true;
    if (word.front() != word.back())
        return false;
    word.pop_back();
    word.erase(0, 1);
    return palindr(word);
}

int main(int argc, char* argv[])
{
    string word;
    cout << "Enter the word: ";
    cin >> word;
    if (word.length() != 5)
    {
        cout << "The word must be 5 digit!" << endl;
        return 1;
    }
    if (palindr(word))
    {
        cout << "The word is a palindrome" << endl;
    }
    else
    {
        cout << "The word is not a palindrome" << endl;
    }
    return 0;
}