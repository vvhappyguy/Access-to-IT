#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
    
};

int main()
{
    Solution s;

    string a1 = "11";
    string a2 = "1";
    cout << s.strStr(a1, a2) << endl;
    a1 = "000000010101";
    a2 = "101";
    cout << s.strStr(a1, a2) << endl;

    return 0;
}