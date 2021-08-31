#include <stdio.h>
#include <string.h>

char choice[8];
char small[11];
char medium[26];
char large[41];

void print_reverse(char *s) {
    // size_t is an integer that holds sizes
    size_t len = strlen(s);
    char *t = s + len - 1;

    while ( t >= s ) {
        printf("%c", *t);
        t = t - 1;
    }
    puts("");
}

int main() {
    puts("'Small' = 10 Characters, 'Medium' = 25 Characters, 'Large' = 40 characters.");
    puts("Please input, 'small', 'medium' or 'large' depending on the size of your string.");
    fgets(choice, 8, stdin);
    choice[strlen(choice) - 1] = '\0';

    if ( !strcmp(choice, "small") )
    {
        printf("The selected option is: '%s' \n", choice);
        puts("Please input the string that you wish to reverse.");
        fgets(small, sizeof small, stdin);
        print_reverse(small);
    }
    else if ( !strcmp(choice, "medium") )
    {
        printf("The selected option is: '%s' \n", choice);
        puts("Please input the string that you wish to reverse.");
        fgets(medium, sizeof medium, stdin);
        print_reverse(medium);
    }
    else if ( !strcmp(choice, "large") )
    {
        printf("The selected option is: '%s' \n", choice);
        puts("Please input the string that you wish to reverse.");
        fgets(large, sizeof large, stdin);
        print_reverse(large);
    }
    else
    {
        puts("ERROR: Invalid option selected.");
        return 1;
    }

    return 0;
}
