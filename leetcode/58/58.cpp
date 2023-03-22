#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s)
{
    size_t len;
    bool isWord = false;
    for (auto c : s)
    {
        if (!isWord && c != ' ')
        {
            len = 1;
            isWord = true;
        }
        else if (isWord && c != ' ')
        {
            len++;
        }
        else if (isWord && c == ' ')
        {
            isWord = false;
        }
    }
    return len;
}

int main()
{
    string str = "Hello world";
    cout << lengthOfLastWord(str) << endl;
    str = "   fly me   to   the moon  ";
    cout << lengthOfLastWord(str) << endl;
    str = "luffy is still joyboy";
    cout << lengthOfLastWord(str) << endl;
    return 0;
}