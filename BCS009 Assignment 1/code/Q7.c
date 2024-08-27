// TODO： 设计一个算法求 1+(1+2)+(1+2+3)+…+(1+2+3+…n), n>2
#include <stdio.h>
#include <math.h>
// 求和
int sum(int n)
{
    int totalSum = 0;
    for (int i = 1; i <= n; i++)
    {
        int currSum = (i * (i + 1)) / 2;
        totalSum += currSum;
    }
    return totalSum;
}
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    if (n <= 2)
    {
        printf("Error\n");
        return 1;
    }

    int result = sum(n);
    printf("Result: %d\n", result);

    return 0;
}