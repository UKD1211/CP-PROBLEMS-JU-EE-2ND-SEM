// BISECTION METHOD

#include <stdio.h>
#include<conio.h>
#include <math.h>
const float euler = 2.7182818284;

float f(float x)
{
    // return (x * x * x) + (12.1 * x * x) + (13.1 * x) + 22.2;
    // return (-10 * x * x * x * x) - (32 * x * x * x) + (32 * x * x) + (8 * x) + 9;
    // return (pow(euler, x)) - (3 * x);
    // return (sin(x) * 4) - (pow(euler, x));
}

int main()
{
    float x0, x1;
    printf("Enter predicted roots - \n");
    scanf("%f", &x0);
    scanf("%f", &x1);
    printf("\nEnter tolerance - \n");
    float e;
    scanf("%f", &e);
    float e1 = 1;
    long long it = 1;
    float old;
    float ans;
    while (e1 > e || it <= 1e5)
    {
        float x2 = (x0 + x1) / 2;
        if (f(x2) * f(x1) > 0)
            x1 = x2;
        else if (f(x2) * f(x0) > 0)
            x0 = x2;
        else if (f(x2) == 0)
        {
            printf("Root is - %0.11f", x2);
            return 0;
        }
        if (it >= 2)
        {
            e1 = (x2 - old) / x2;
        }
        old = x2;
        it++;
        ans = x2;
    }
    printf("Root is %0.11f", ans);
    return 0;
}