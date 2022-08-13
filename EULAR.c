// EULARS METHOD
#include <stdio.h>
#include<conio.h>
#include <math.h>

float fxy(float, float);
int main()
{
    float x1, x2;
    float y0;
    float h, w;
    int i;
    printf("Enter the lower limit of x\n");
    scanf("%f", &x1);
    printf("Enter the upper limit of x\n");
    scanf("%f", &x2);
    printf("Enter the initial value of y\n");
    scanf("%f", &y0);
    printf("Enter the value of h\n");
    scanf("%f", &h);
    w = (x2 - x1) / h;
    float x = x1, y = y0;
    for (i = 1; i <= w; i++)
    {
        y = y + h * fxy(x, y);
        x = x + h;
        printf("y%d=%f\n", i, y);
    }
    return 0;
}
float fxy(float a, float b)
{
    return ((a * a) + (b * b));
}