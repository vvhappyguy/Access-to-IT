#include <algorithm>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// 1791. Find Center of Star Graph
class Solution1791
{
public:
    int findCenter(vector<vector<int>>& edges)
    {
        std::map<int, int> nodesCount;
        size_t countCon = edges.size();
        for (const auto& con : edges)
            for (const auto& node : con)
                nodesCount[node]++;
        auto findResult = std::find_if(std::begin(nodesCount),
                                       std::end(nodesCount),
                                       [&](const std::pair<int, int>& pair) { return pair.second == countCon; });
        return findResult->first;
    }

    int findCenterImp(vector<vector<int>>& e)
    {
        return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
    }

    void start()
    {
        cout << typeid(this).name() << endl;
        vector<vector<int>> edges = {{1,2},{2,3},{4,2}};
        cout << findCenter(edges) << endl;
        cout << findCenterImp(edges) << endl;
    }
};


int main()
{
    Solution1791 s1791;
    s1791.start();
    return 0;
}
