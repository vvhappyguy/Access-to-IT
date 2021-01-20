#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int a[10];
    for(int i = 0; i < 10; i++)
        a[i] = i;
    printf("%d", binsearch(4, a, 10));
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;

    while (low < high) {
        unsigned mid = (low + high) >> 1;
        if (v[mid] < x)
            low  = mid + 1;
        else
            high = mid;
    }

    return ((high == low) && (v[high] == x)) ? low : -1;
}