// TODO:设顺序表 L 有 10 个整数。设计一个算法，以第一个元素为分界线（基准），将所有小于等于它的元素移到该元素的前面，将所有大于它的元素移到该元素的后面。
#include <stdio.h>
void partition(int L[], int n)
{
    int pivot = L[0];
    int temp;
    int left = 1;      // left指向第一个元素
    int right = n - 1; // right指向最后一个元素

    while (left <= right)
    {
        while (left <= right && L[left] <= pivot)
        {
            left++;
        }
        while (left <= right && L[right] > pivot)
        {
            right--;
        }
        if (left < right)
        {
            temp = L[left];
            L[left] = L[right];
            L[right] = temp;
        }
    }
    pivot = L[right];
    L[right] = L[0];
    L[0] = pivot;

    if (n <= 1)
    {
        return;
    }
}

int main()
{
    int L[] = {50, 76, 20, 49, 8, 99, 64, 88, 34, 67};
    int n = sizeof(L) / sizeof(L[0]);
    partition(L, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", L[i]);
    }
    return 0;
}