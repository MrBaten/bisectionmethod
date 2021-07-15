#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<math.h>

#define f(x) x*x*x - 4*x - 9

int main()
{
    float x0, x1, x2, f0, f1, f2, E;
    int step = 1;
    system("COLOR C3");
    printf("\t\t\tFinding a function's Root using Bisection Method\n");
execute_again:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY);
    printf("\nEnter two initial guesses:\n");
    scanf("%f%f", &x0, &x1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);
    printf("Enter tolerable error:\n");
    scanf("%f", &E);
    f0 = f(x0);
    f1 = f(x1);
    if( f0 * f1 > 0.0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED);
        printf("Incorrect Initial Guesses. \nYou must have to fill (f0*f1<0) Value. So try a valid value...\n");
        goto execute_again;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED);
    printf("\t\tOur Given Equation : f(x) = 3x - cos(x) - 1\n");
    printf("\t\t$Finding the root of this given equation....\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    printf("___________________________________________________________________________________________________");
    printf("\n| Iteration\t| x0\t\t\t| x1\t\t\t| x2(root)\t\t| f(x2)   |\n");
    do{
        x2 = (x0 + x1)/2;
        f2 = f(x2);
        printf("___________________________________________________________________________________________________\n");
        printf("| %d\t\t| %f\t\t| %f\t\t| %f\t\t|%f   |\n",step, x0, x1, x2, f2);
        if( f0 * f2 < 0){
            x1 = x2;
            f1 = f2;
        }
        else{
            x0 = x2;
            f0 = f2;
        }
        step = step + 1;
    }
    while(fabs(f2)>E);
    printf("___________________________________________________________________________________________________");
    printf("\nOur Root is X2: %f", x2);
    getchar();
    getch();
}
