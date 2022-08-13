// LAGRANGE INTERPOLATION METHOD

#include <stdio.h>
#include <stdio.h>
#include <math.h>

int main()
{
    printf("LAGRANGE METHOD\n");
    int n;
    float a;
    printf("Enter the number of user-input data\n");
    scanf("%d", &n);
    float x[n];
    float y[n];
    printf("Enter the value of x for which f(x) is to be evaluated\n");
    scanf("%f", &a);
    int i, i1, j;
    float k, s;
    s = 0;
    for (i = 0; i < n; i++)
    {
        printf("Enter x%d\n", (i + 1));
        scanf("%f", &x[i]);
        printf("Enter fx(%d)\n", (i + 1));
        scanf("%f", &y[i]);
    }
    for (j = 0; j < n; j++)
    {
        k = y[j];
        for (i1 = 0; i1 < n; i1++)
        {
            if (i1 != j)
            {
                k = k * ((a - x[i1]) / (x[j] - x[i1]));
            }
        }
        s = s + k;
    }
    printf("f(%f)=%f\n", a, s);
    return 0;
}