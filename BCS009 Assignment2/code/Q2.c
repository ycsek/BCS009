// TODO:有一个顺序表 L，假设元素类型 ElemType 为整型。设计一个尽可能高效的算法，将所有奇数移动到偶数的前面。
#include <stdio.h>
void range(int L[], int n)
{
    int left = 0;
    int right = n - 1;
    int temp;
    while (left < right)
    {
        // 左指针指向奇数，继续向右移动
        while (left < right && L[left] % 2 != 0)
        {
            left++;
        }
        // 右指针指向偶数，继续向左移动
        while (left < right && L[right] % 2 == 0)
        {
            right--;
        }
        // 交换左右指针指向的元素
        if (left < right)
        {
            temp = L[left];
            L[left] = L[right];
            L[right] = temp;
        }
    }
}
int main()
{
    int L[] = {50, 70, 21, 49, 8, 99, 64, 88, 35, 67};
    int n = sizeof(L) / sizeof(L[0]);
    range(L, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", L[i]);
    }
    return 0;
}