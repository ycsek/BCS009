// TODO: 设计一个算法：求一元二次方程 ax^2+bx+c=0 的根

#include <stdio.h>
#include <math.h>

// 复数结构体
typedef struct
{
    double real;
    double imaginary;
} Complex;

// 计算一元二次方程的根
void quadratic_roots(double a, double b, double c, Complex *root1, Complex *root2)
{
    // 计算判别式
    double d = b * b - 4 * a * c;
    // 产生两个不相等的实根
    if (d > 0)
    {
        root1->real = (-b + sqrt(d)) / (2 * a);
        root1->imaginary = 0;
        root2->real = (-b - sqrt(d)) / (2 * a);
        root2->imaginary = 0;
    }
    // 产生两个相等的实根
    else if (d == 0)
    {
        root1->real = -b / (2 * a);
        root1->imaginary = 0;
        root2->real = -b / (2 * a);
        root2->imaginary = 0;
    }
    // 产生两个共轭复根
    else
    {
        root1->real = -b / (2 * a);
        root1->imaginary = sqrt(-d) / (2 * a);
        root2->real = -b / (2 * a);
        root2->imaginary = -sqrt(-d) / (2 * a);
    }
}
// 打印复数
void print(const char *prefix, Complex c)
{
    if (c.imaginary == 0)
    {
        printf("%s %f\n", prefix, c.real);
    }
    else if (c.imaginary > 0)
    {
        printf("%s %f + %fi\n", prefix, c.real, c.imaginary);
    }
    else
    {
        printf("%s %f - %fi\n", prefix, c.real, -c.imaginary);
    }
}

int main()
{
    // 输入系数
    double a, b, c;
    printf("Enter a, b, c:");
    scanf("%lf %lf %lf", &a, &b, &c);
    Complex root1, root2;
    quadratic_roots(a, b, c, &root1, &root2);
    print("Root1:", root1);
    print("Root2:", root2);
    return 0;
}
