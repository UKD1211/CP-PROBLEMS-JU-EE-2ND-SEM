// NEWTON INTERPOLATION METHOD

#include <stdio.h>
#include <conio.h>
#include <math.h>

int fact(int);
float make1(float, int);
float make2(float, int);
int main()
{

    printf("Newton'S Interpolation Method\n");

    int n;
    printf("Enter the number of sample data to be entered: ");
    scanf("%d", &n);

    float x_val[n];
    float fx_val[n][n];

    int i, j = 0;

    for (i = 0; i < n; i++)
    {
        printf("\nEnter x value: ");
        scanf("%f", &x_val[i]);
        printf("\nEnter corresponding f(x) value: ");
        scanf("%f", &fx_val[0][i]);
    }

    float x;
    printf("\nEnter the interpolating point:");
    scanf("%f", &x);
    int c = 10;

    float s1, s2;
    while (c != 0)
    {
        printf("\nEnter\n 1 for Forward Elimination Method \n 2 for Backward Elimination \n 0 to exit.");
        scanf("%d", &c);
        switch (c)
        {
        case 0:
            break;
        case 1:
            for (i = 0; i < (n - 1); i++)
            {
                for (j = 0; j < (n - i - 1); j++)
                {
                    fx_val[i + 1][j] = fx_val[i][j + 1] - fx_val[i][j];
                }
            }
            printf("\n\n\n");
            for (i = 0; i < n; i++)
            {
                printf("\n");
                for (j = 0; j < (n - i); j++)
                {
                    printf("%f  ", fx_val[j][i]);
                }
            }
            s1 = (x - x_val[0]) / (x_val[1] - x_val[0]);

            float in1 = fx_val[0][0];
            for (i = 0; i < n - 1; i++)
            {
                in1 = in1 + (make1(s1, (i + 1)) / fact(i + 1)) * fx_val[i + 1][0];
            }
            printf("\n\nThe interpolated value is: %f\n\n", in1);
            break;

        case 2:
            for (i = 0; i < (n - 1); i++)
            {
                for (j = 0; j < (n - i - 1); j++)
                {
                    fx_val[i + 1][j] = fx_val[i][j + 1] - fx_val[i][j];
                }
            }

            for (i = 0; i < n; i++)
            {
                printf("\n");
                for (j = 0; j < (n - i); j++)
                {
                    printf("%f  ", fx_val[j][i]);
                }
            }

            s2 = (x - x_val[n - 1]) / (x_val[1] - x_val[0]);
            float in2 = fx_val[0][n - 1];
            for (i = 0; i < n - 1; i++)
            {
                in2 = in2 + (make2(s2, (i + 1)) / fact(i + 1)) * fx_val[i + 1][n - i - 2];
            }
            printf("\n\nThe interpolated value is: %f\n\n", in2);
            break;
        }
    }
}

int fact(int x)
{
    int f = 1;
    int i = 0;
    for (i = 1; i <= x; i++)
    {
        f = f * i;
    }
    return f;
}

float make1(float s, int n)
{
    int i = 0;
    float r = 1;

    for (i = 0; i < n; i++)
    {
        r = r * (s - i);
    }
    return r;
}

float make2(float s, int n)
{
    int i = 0;
    float r = 1;

    for (i = 0; i < n; i++)
    {
        r = r * (s + i);
    }
    return r;
}