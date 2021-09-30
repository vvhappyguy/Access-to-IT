// https://leetcode.com/problems/two-sum/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int * res = malloc(sizeof(int) * 2);
    *returnSize = 2;
    for(int j = 0; j < numsSize; ++j)
        for(int i = 0; i < numsSize; ++i)
        {
            if(i != j)
            {
                if(nums[i] + nums[j] == target)
                {
                    res[0] = j;
                    res[1] = i;
                    goto end;
                }
            }   
        }
    free(res);
    res = 0;
    returnSize = 0;
end:
    return res;
}

int main(int args, char* argv[]){
    int size = 3;
    int array[3] = {3, 2, 4};
    int target = 6;
    int retSize = 0;

    int* res = twoSum(array, size, target, &retSize);
    // printf("%p", res);
    if(res)
    {
        for(int i = 0; i < retSize; ++i)
        {
            printf("res[%d]=%d\n", i, res[i]);
        }
    }

    return 0;
}