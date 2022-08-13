// FALSE POSITION METHOD

#include <stdio.h>
#include <conio.h>
#include <math.h>

float f(float x)
{

    // #define f(x) (x * x * x + 12.1 * x * x + 3.1 * x + 22.2)
    // #define f(x) (-10 * x * x * x * x) - (32 * x * x * x) + (32 * x * x) + (8 * x) + 9
    // #define f(x) exp(x) - 3*x
    return 4 * sin(x) - exp(x);
}
float falsi(float a, float b, float p, float q)
{
    return (a * q - b * p) / (q - p);
}
int main()
{
    float a, b;
    printf("enter the value of a and b\n: ");

    scanf("%f %f", &a, &b);
    float it;
    printf("enter the value of IT\n: ");
    scanf("%f", &it);
    float x = 0;
    for (int i = 0; i < it; i++)
    {
        x = falsi(a, b, f(a), f(b));
        if (f(a) * f(x) == 0)
            break;
        else if (f(a) * f(x) < 0)
            b = x;
        else
            a = x;
    }
    printf("The root is : %f", x);
}