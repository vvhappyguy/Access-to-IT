#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        size_t word1_size = word1.size();
        size_t word2_size = word2.size();
        string result;
        size_t w1 = 0;
        size_t w2 = 0;
        while (w1 < word1_size && w2 < word2_size)
        {
            if ((w1 + w2) % 2 == 0)
            {
                result += word1[w1];
                w1++;
            }
            else
            {
                result += word2[w2];
                w2++;
            }
                }
        while (w1 < word1_size)
        {
            result += word1[w1];
            w1++;
        }
        while (w2 < word2_size)
        {
            result += word2[w2];
            w2++;
        }
        return result;
    }
};

int main()
{
    Solution s;
    string str1, str2;

    str1 = "abc";
    str2 = "pqr";
    cout << s.mergeAlternately(str1, str2) << endl;
    cout << "------" << endl;

    str1 = "ab";
    str2 = "pqrs";
    cout << s.mergeAlternately(str1, str2) << endl;
    cout << "------" << endl;

    str1 = "abcd";
    str2 = "pq";
    cout << s.mergeAlternately(str1, str2) << endl;
    cout << "------" << endl;

    return 0;
}