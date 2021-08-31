//
// Created by James Miles on 31/08/2021.
//

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *delivery = "";
    int thick = 0;
    int count = 0;
    char ch;

    while ( (ch = getopt(argc, argv, "d:t")) != EOF)    // 'd' is followed by : as it takes an argument
        switch (ch) {
            case 'd':
                delivery = optarg;  // delivery variable points to the argument supplied with the 'd' option
                break;
            case 't':   // in C setting something to '1' is the same as setting it to true
                thick = 1;
                break;
            default:
                fprintf(stderr, "Unknown option: '%s'\n", optarg);
                return 1;
        }

    argc -= optind;
    argv += optind;

    if (thick)
        puts("Thick crust.");

    if (delivery[0])
        printf("To be delivered %s.\n", delivery);

    puts("Ingredients:");

    for (count = 0; count < argc; count++ )
        puts(argv[count]);

    return 0;
}
