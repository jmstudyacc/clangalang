//
// Created by James Miles on 31/08/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char cardName[3];
    int count = 0;
    // do...while loop to run the loop at least ONCE before condition is checked
    do {
        // puts() is like println() and cannot take positional variable substitution
        puts("Please input your card, to find its value:");
        // scanf() scans the specified number of positions in the input and puts into a data structure
        scanf("%2s", cardName);
        int val = 0;

        // use of switch to avoid lengthy if branches
        switch (cardName[0]) {
            case 'K':
            case 'Q':
            case 'J':
                val = 10;
                break;
            case 'A':
                val = 11;
                break;
            case 'X':
                continue;   // break would not break out of the loop, it would only break out of the switch
            default:
                // atoi() takes a character and casts it into an integer
                val = atoi(cardName);
                if ( (val < 1 ) || ( val > 10 )) {
                    puts("ERROR: Invalid card entered.");
                    continue;
                }
        }

        if (( val > 2) && ( val < 7)) {
            count++;
        } else if ( val == 10 ) {
            count--;
        }
        printf("Current count: %i\n", count);

        // while loop condition here to check after the obligatory first cycle
    } while ( cardName[0] != 'X');

    return 0;
}
