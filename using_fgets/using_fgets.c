//
// Created by James Miles on 31/08/2021.
//

#include <stdio.h>

int main() {
    char food[5];
    printf("Enter favourite food: ");
    // begins with taking pointer to a buffer (food), takes the max size of the string (sizeof(food)) - be sure that you are not passing a pointer variable
    fgets(food, sizeof(food), stdin);   // finally, stdin = data comes from keyboard
    return 0;
}
