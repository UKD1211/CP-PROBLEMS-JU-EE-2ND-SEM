// RUNGEKUTTA 4th order METHOD

#include <stdio.h>
#include <math.h>
#include <conio.h>

float f(float x, float y){
    return (2 * (x * x)) - y;
    //return (2 * x * y) - (y * y);
    //return (2 * (x * x)) - (3 * x) + 4;
}

double xi, yi, xn, h, yval, k1, k2, k3, k4, k;
int n;

void main(){
    printf("Enter Initial Condition\n");
    printf("xi = ");
    scanf("%lf", &xi);
    printf("yi = ");
    scanf("%lf", &yi);
    printf("Enter calculation point xn = ");
    scanf("%lf", &xn);
    printf("Enter number of steps: ");
    scanf("%d", &n);
    h = (xn - xi) / n;
    for (int i = 0; i < n; i++){
        k1 = h * (f(xi, yi));
        k2 = h * (f((xi + h / 2), (yi + k1 / 2)));
        k3 = h * (f((xi + h / 2), (yi + k2 / 2)));
        k4 = h * (f((xi + h), (yi + k3)));
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yval = yi + k;
        printf("%0.6lf\t%0.6lf\t%0.6lf\n", xi, yi, yval);
        xi = xi + h;
        yi = yval;
    }
    printf("\nValue of y at x = %0.6lf is %0.6lf",xn, yval);
}