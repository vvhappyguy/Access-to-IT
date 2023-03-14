#include <cmath>
#include <function>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Time limit - need to learn heap + priority queue
int minStoneSumVector(vector<int>& piles, int k)
{
    int max_value, max_index;
    int sum = 0;
    for (auto p : piles)
        sum += p;
    while (k != 0)
    {
        max_value = piles[0];
        max_index = 0;

        for (int i = 1; i < piles.size(); i++)
        {
            if (piles[i] > max_value)
            {
                max_value = piles[i];
                max_index = i;
            }
        }
        int diff = floor(piles[max_index] / 2);
        piles[max_index] -= diff;
        sum -= diff;
        k--;
    }
    return sum;
}

// Works: 92% runtime - 5% memory - 10:05-10:35
int minStoneSumHeap1(vector<int>& piles, int k)
{
    std::priority_queue<int> q1;
    int sum = 0;
    for (auto p : piles)
    {
        q1.push(p);
        sum += p;
    }

    while (k != 0)
    {
        int elem = q1.top();
        q1.pop();
        int diff = floor(elem / 2);
        elem -= diff;
        q1.push(elem);
        sum -= diff;
        k--;
    }
    return sum;
}

// Works: 80% runtime - 84% memory
int minStoneSum(vector<int>& piles, int k)
{
    std::priority_queue<int> q1(piles.begin(), piles.end());

    while (k != 0)
    {
        int elem = q1.top();
        q1.pop();
        elem -= elem / 2;
        q1.push(elem);
        k--;
    }
    int sum = 0;
    while (!q1.empty())
    {
        sum += q1.top();
        q1.pop();
    }
    return sum;
}

// Best memory from leetcode
// Nice c++-styled code
int minStoneSum(vector<int>& piles, int k)
{
    make_heap(begin(piles), end(piles));
    while (--k >= 0)
    {
        int x = piles.front();
        pop_heap(begin(piles), end(piles));
        piles.pop_back();
        piles.emplace_back((x + 1) / 2);
        push_heap(begin(piles), end(piles));
    }
    return accumulate(cbegin(piles), cend(piles), 0);
}

// Best runtime from leetcode
// Values are like indexes
int minStoneSum(vector<int>& piles, int k)
{
    int counts[1'0000 + 10] = {};

    for (int v : piles)
    {
        counts[v]++;
    }

    for (int i = 1'0000; i > 0 && k; i--)
    {
        const int removed = min(k, counts[i]);
        counts[i - (i / 2)] += removed;
        k -= removed;
        counts[i] -= removed;
    }

    int res = 0;

    for (int i = 1'0000; i > 0; i--)
    {
        res += i * counts[i];
    }

    return res;
}

int main()
{
    vector<int> test = {5, 4, 9};
    int test_k = 2;
    cout << minStoneSum(test, test_k) << endl;

    test = {4, 3, 6, 7};
    test_k = 3;
    cout << minStoneSum(test, test_k) << endl;
    return 0;
}