//
// Created by James Miles on 31/08/2021.
//

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("The value of INT_MAX is %i\n", INT_MAX);
    printf("The value of INT_MIN is %i\n", INT_MIN);
    printf("An int takes %zu bytes\n", sizeof(int));
    puts("");
    printf("The value of FLT_MAX is %f\n", FLT_MAX);
    printf("The value of FLT_MIN is %f\n", FLT_MIN);
    printf("A float takes %zu bytes\n", sizeof(float));
    puts("");
    printf("The value of DBL_MAX is %f\n", DBL_MAX);
    printf("The value of DBL_MIN is %f\n", DBL_MIN);
    printf("A double takes %zu bytes\n", sizeof(double));

    return 0;
}
