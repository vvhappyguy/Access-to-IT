#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
    for (size_t i = 0; i < flowerbed.size() && n != 0; ++i)
    {
        if (flowerbed[i] == 1)
        {
            continue;
        }
        // Первый элемент и не последний
        if (i == 0 && (i + 1) < flowerbed.size())
        {
            if (flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        // Между первым и последним
        else if (i > 0 && (i + 1) < flowerbed.size())
        {
            if (flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        // Между последний
        else if (i > 0 && (i + 1) >= flowerbed.size())
        {
            if (flowerbed[i - 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        else
        {
            flowerbed[i] = 1;
            n--;
        }
    }
    return n == 0;
}

// prettier solution
bool canPlaceFlowersI(vector<int>& flowerbed, int n)
{
    int len = flowerbed.size();
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);

    for (int i = 1; i <= len; i++)
    {
        if (flowerbed[i] + flowerbed[i - 1] + flowerbed[i + 1] == 0)
        {
            n--;
            i++;
        }
    }

    if (n > 0)
        return false;

    return true;
}

int main()
{
    vector<int> flowers = {1, 0, 0, 0, 1};
    int n = 1;
    cout << canPlaceFlowers(flowers, n) << endl;

    flowers = {1, 0, 0, 0, 1};
    n = 2;
    cout << canPlaceFlowers(flowers, n) << endl;
}