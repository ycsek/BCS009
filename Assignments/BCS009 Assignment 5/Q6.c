#include <stdio.h>
#include <stdlib.h> 

void computeNextArray(const char *pattern, int *next, int length)
{
    int i = 0, j = -1;
    next[0] = -1; // 初始化第一个元素

    while (i < length - 1)
    {
        if (j == -1 || pattern[i] == pattern[j])// 如果j=-1或者pattern[i]等于pattern[j]，则递增i和j，然后将next[i]赋值为j
        {
            i++;
            j++;
            next[i] = j;
        }
        else// 否则，将j赋值为next[j]
        {
            j = next[j];
        }
    }
}

int main()
{
    const char *pattern = "ababaa";
    int length = 6;                                  // 模式串的长度
    int *next = (int *)malloc(length * sizeof(int)); // 动态分配内存

    computeNextArray(pattern, next, length);

    printf("Next array: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", next[i]);
    }
    printf("\n");

    free(next); // 释放内存

    return 0;
}

