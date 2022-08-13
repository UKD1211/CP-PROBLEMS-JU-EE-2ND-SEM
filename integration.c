#include<stdio.h>
#include<math.h>

int n;

double Trapezoidal(double X[], double Y[]){
    float sum = 0;
    float h = (X[n - 1] - X[0]) / (n - 1);
    for (int i = 0; i < n; i++){
        if (i == 0 || i == n - 1) sum += Y[i] / 2;
        else sum += Y[i];
    }
    float ans = sum * h;
    return ans;
}

double SimpsonOneThird(double X[], double Y[]){
    float sum = 0;
    float h = (X[n - 1] - X[0]) / (n - 1);
    h = (h / 3);
    for (int i = 0; i < n; i++){
        if (i == 0 || i == n - 1) sum += Y[i];
        else if (i & 1) sum += 4 * Y[i];
        else sum += 2 * Y[i];
    }
    float ans = sum * h;
    return ans;
}


double SimpsonThreeEighth(double X[], double Y[]){
    float sum = 0;
    float h = (X[n - 1] - X[0]) / (n - 1);
    h = ((h * 3 )/ 8);
    for (int i = 0; i < n; i++){
        if (i == 0 || i == n - 1) sum += Y[i];
        else if (i % 3 == 0) sum += 2 * Y[i];
        else sum += 3 * Y[i];
    }
    float ans = sum * h;
    return ans;
}

void main(){
    FILE *fptr;
    fptr=fopen("integration1.txt","r");
    // fptr=fopen("integration2.txt","r");
    // fptr=fopen("integration3.txt","r");
    // fptr=fopen("integration4.txt","r");
    fscanf(fptr,"%d",&n);
    double X[n], Y[n];
    for (int i = 0; i < n; i++) fscanf(fptr,"%lf",&X[i]);
    for (int i = 0; i < n; i++) fscanf(fptr,"%lf",&Y[i]);
    fclose(fptr);
    printf("Using Trapezoidal Method\n");
    printf("%lf\n\n", Trapezoidal(X, Y));
    printf("Using Simpson One Third Method\n");
    printf("%lf\n\n", SimpsonOneThird(X, Y));
    printf("Using Simpson Three Eighth Method\n");
    printf("%lf\n\n", SimpsonThreeEighth(X, Y));
}