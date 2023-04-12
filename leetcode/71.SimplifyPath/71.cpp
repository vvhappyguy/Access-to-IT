#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(const vector<string>& nums)
{
    for (auto& num : nums)
    {
        std::cout << num << "|";
    }
    cout << std::endl;
}

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> v;
        string tmp = "";
        for (size_t i = 0; i < path.size(); i++)
        {
            if (path[i] == '/')
            {
                v.push_back(tmp);
                tmp = "";
            }
            tmp += path[i];
        }
        v.push_back(tmp);
        tmp = "";
        printVector(v);
        vector<string> mod;
        int backs = 0;
        for (int i = v.size() - 1; i >= 0; --i)
        {
            if(v[i] == "/.")
            {

            }
            else if (v[i] == "/")
            {
            }
            else if (v[i] == "/..")
            {
                backs++;
            }
            else
            {
                //tmp += v[i];
                if(backs > 0)
                {
                    backs--;
                }
                else
                {
                    mod.push_back(v[i]);
                }
                
            }
        }
        cout << endl;
        printVector(mod);
        cout << endl;
        for (int i = mod.size() - 1; i >= 0; i--)
        {
            tmp += mod[i];
        }
        if(tmp == "")
        {
            tmp = "/";
        }
        return tmp;
    }
};

int main()
{
    Solution s;

    string test = "/home/";
    cout << s.simplifyPath(test) << endl;
    cout << "--------------------------------" << endl;

    test = "/../";
    cout << s.simplifyPath(test) << endl;
    cout << "--------------------------------" << endl;

    test = "/home//foo/";
    cout << s.simplifyPath(test) << endl;
    cout << "--------------------------------" << endl;

    test = "/a/./b/../../c/";
    cout << s.simplifyPath(test) << endl;
    cout << "--------------------------------" << endl;

    test = "/a//b////c/d//././/..";
    cout << s.simplifyPath(test) << endl;
    cout << "--------------------------------" << endl;
    return 0;
}