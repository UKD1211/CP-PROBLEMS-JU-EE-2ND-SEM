// LEAST SQUARE POLYNOMIAL

#include <stdio.h>
#include <conio.h>
#include <math.h>

void gaussEliminationLS(int m, int n, double a[m][n], double x[n - 1])
{
    int i, j, k;
    for (i = 0; i < m - 1; i++)
    {

        for (k = i + 1; k < m; k++)
        {

            if (fabs(a[i][i]) < fabs(a[k][i]))
            {

                for (j = 0; j < n; j++)
                {
                    double temp;
                    temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }

        for (k = i + 1; k < m; k++)
        {
            double term = a[k][i] / a[i][i];
            for (j = 0; j < n; j++)
            {
                a[k][j] = a[k][j] - term * a[i][j];
            }
        }
    }

    for (i = m - 1; i >= 0; i--)
    {
        x[i] = a[i][n - 1];
        for (j = i + 1; j < n - 1; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
}

void printMatrix(int m, int n, double matrix[m][n])
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int N;
    int i;
    int j;
    int n;
    FILE *fp;
    // fp=fopen("leastsquarePOL.txt","r");
    fp=fopen("leastsquarePOL1.txt","r");
    fscanf(fp,"%d",&N);
    double x[N], y[N];
    for ( i = 0; i <N; i++)
    {
            fscanf(fp,"%lf",&x[i]);
            fscanf(fp,"%lf",&y[i]);

    }
    
     printf("Enter the degree of polynomial to be used:\n");
     scanf("%d", &n);

    double X[2 * n + 1];
    for (i = 0; i <= 2 * n; i++)
    {
        X[i] = 0;
        for (j = 0; j < N; j++)
        {
            X[i] = X[i] + pow(x[j], i);
        }
    }

    double B[n + 1][n + 2];
    // rhs
    double Y[n + 1];
    for (i = 0; i <= n; i++)
    {
        Y[i] = 0;
        for (j = 0; j < N; j++)
        {
            Y[i] = Y[i] + pow(x[j], i) * y[j];
        }
    }
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            B[i][j] = X[i + j];
        }
    }
    for (i = 0; i <= n; i++)
    {
        B[i][n + 1] = Y[i];
    }
    double A[n + 1];
    printf("The polynomial fit is given by the equation:\n");
    printMatrix(n + 1, n + 2, B);
    gaussEliminationLS(n + 1, n + 2, B, A);
    for (i = 0; i <= n; i++)
    {
        printf("%lfx^%d+", A[i], i);
    }
}
