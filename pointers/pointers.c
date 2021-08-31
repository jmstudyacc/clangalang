#include <stdio.h>

void pointers() {
    int numbers[] = {10, 20, 30};
    int *option = numbers;

    // the index value is simply the number to be added to the array pointer variable[5] == *(variable + 5)
    printf("Value at index, 0: %i\n", numbers[0]);
    printf("Value of array variable (pointer): %i\n", *numbers);
    puts("");
    // indexing into an array is basically syntactic sugar to avoid the below mess
    printf("First value of the array is at: %p\n", &numbers[0]);
    printf("First value of the array, no-index syntax, is at: %p\n", numbers);
    puts("");
    printf("Second value of the array is at: %p\n", &numbers[1]);
    printf("Second value of the array, non-index syntax, is at: %p\n", numbers+1);
    puts("");
    printf("Third value of the array is at: %p\n", &numbers[2]);
    printf("Third value of the array, non-index syntax, is at: %p\n", numbers+2);
    puts("");
    printf("Value at index, 1: %i\n", numbers[1]);
    printf("Value of array variable + 1 (pointer arithmetic): %i\n", *(numbers + 2));

    numbers[0] = 29;
    numbers[1] = numbers[2];
    numbers[2] = *option;   // assign numbers[2] to the first value in the numbers array
    printf("The selected number: %i\n", numbers[2]);
}

void arraySkip(char *msg) {
    puts(msg + 6);
}

int main() {
    pointers();
    puts("How do you specify from where to print out of a char array?");
    arraySkip("Don't call me");
    return 0;
}
