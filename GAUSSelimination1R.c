// GAUSS ELIMINATION METHOD

#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int i, j, k, n;
    float a[20][20], x[20];
    double s, p;
    printf("Enter the number of equations : ");
    scanf("%d", &n);
    printf("\nEnter the co-efficients of the equations :\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
        printf("b[%d] = ", i + 1);
        scanf("%f", &a[i][n]);
    }
    for (k = 0; k <= n - 1; k++)
    {
        for (i = k + 1; i < n; i++)
        {
            p = a[i][k] / a[k][k];
            for (j = k; j <= n; j++)
            {
                a[i][j] = a[i][j] - (p * a[k][j]);
                printf("\n a[%d][%d] = %f", i, j, a[i][j]);
            }
        }
    }
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        s = 0;
        for (j = i + 1; j < n; j++)
        {
            s += (a[i][j] * x[j]);
            x[i] = (a[i][n] - s) / a[i][i];
        }
    }
    printf("\nThe result is :\n");
    for (i = 0; i < n; i++)
    {
        printf("\nx[%d] = %.2f", i + 1, x[i]);
    }

    return 0;
}
