// NEWTON RAPHSON METHOD

#include <stdio.h>
#include<conio.h>
#include <math.h>

float g(float x);
float f(float x);
float f1(float x);
float f2(float x);
float check(float x);
int main()
{
    float x0;
    float x1;
    printf("Enter initial guess\n");
    scanf("%f", &x0);
    float e = 0.00001;
    int max = 1000;
    int i = 0;
    while (fabs(g(x0) - x0) > e)
    {
        x1 = g(x0);
        if (fabs(check(x0)) > 1)
        {
            printf("Try better guess,may be non convergent\n");
            printf("Enter initial guess\n");
            scanf("%f", &x0);
            i = -1;
        }
        if (i != -1)
            x0 = x1;
        ++i;
        if (i > 0)
            printf("Root after %d iterations is %f f(%f) = %f\n", i, x1, x1, f(x1));
        if (i == max)
        {
            printf("Maximum number of iterations reached\n");
            break;
        }
    }
    printf("Final root = %f", x1);
    return 0;
}
float g(float x)
{
    float y = x - f(x) / f1(x);
    return y;
}

float f(float x)
{

    // float y = (x * x * x + 12.1 * x * x + 3.1 * x + 22.2);
    // float y = (-10 * x * x * x * x) - (32 * x * x * x) + (32 * x * x) + (8 * x) + 9;
    // float y = 4 * sin(x) - exp(x);
    float y=exp(x) - 3*(x);

    return y;
}
float f1(float x) // first derivative
{

    // float y = 3 * x * x + 24.2 * x + 3.1;
    // float y= (-40*x*x*x)-(96*x*x)+64*x+8;
    // float y= 4*cos(x)-exp(x);
    float y=exp(x)-3;

    return y;
}
float f2(float x) // second derivative
{

    // float y = 6 * x + 24.2;
    // float y=-120*x*x-192*x+64;
    // float y=-4*sin(x)-exp(x);
    float y=exp(x);
    return y;
}
float check(float x)
{
    float y = f(x) * f1(x) / (f2(x) * f2(x));
    return y;
}