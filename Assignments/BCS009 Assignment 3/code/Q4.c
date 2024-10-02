/*
 * @Author: Yuchen Shi
 * @Date: 14-09-2024 18:54:42
 * @Last Editors: Y.Shi
 * @Contact Last Editors: yuchenshi327@outlook.com
 * @LastEditTime: 18-09-2024 19:40:38
 */
#include <stdio.h>
#include <stdlib.h>

// 用于找到两个升序数组的中位数
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{

    if (nums1Size > nums2Size)
    {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int low = 0, high = nums1Size;
    // 二分查找
    while (low <= high)
    {
        int partitionX = (low + high) / 2;
        int partitionY = (nums1Size + nums2Size + 1) / 2 - partitionX;

        // 计算partitionX和partitionY的边界元素
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == nums1Size) ? INT_MAX : nums1[partitionX];
        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == nums2Size) ? INT_MAX : nums2[partitionY];

        // 检查是否找到了中位数
        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            // 奇数个元素
            if ((nums1Size + nums2Size) % 2 == 1)
            {
                return (double)max(maxLeftX, maxLeftY);
            }
            else
            { // 偶数个元素
                return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
            }
        }
        else if (maxLeftX > minRightY)
        {
            // 减少nums1的右半部分
            high = partitionX - 1;
        }
        else
        {
            // 增加nums1的左半部分
            low = partitionX + 1;
        }
    }
    // 如果没有找到中位数，返回-1
    return -1;
}

int main()
{
    //给定两个升序列
    int nums1[] = {1, 3, 5, 7, 9};
    int nums2[] = {2, 4, 6, 8, 10};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("The median is: %.2f\n", median);

    return 0;
}