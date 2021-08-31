//
// Created by James Miles on 31/08/2021.
//

#include <stdio.h>

int main() {
    float latitude;
    float longitude;
    char info[80];
    int started = 0;

    puts("data=[");
    // [^\n] = give every character up to the end of the line
    while (scanf("%f, %f, %79[^\n]", &latitude, &longitude, info) == 3) {   // scanf() takes pointers to the number variables - info is an array pointer basically
        if ( started )
            printf(",\n");
        else
            started = 1;
        if ( (latitude < -90) || (latitude > 90) )
        {
            //printf("Invalid latitude: %f\n", latitude);
            fprintf(stderr, "Invalid latitude: %f\n", latitude);    // using fprintf() you now print to stderr which by default displays on the terminal
            return 2;   // This will error the program out with error status of 2
        }
        else if ((longitude < -180) || (longitude > 180) )
        {
            //printf("Invalid longitude: %f\n", longitude);
            fprintf(stderr, "Invalid longitude: %f\n", longitude);
            return 2;
        }
        // no '&' needed here as printf() is using the VALUES and not doing anything to the specified variables
        printf("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
    }
    puts("\n]");
    return 0;
}

// if you want to use the Linux tools to handle this you'll need to add the right redirects
// < = redirects data to the program/file preceding the <
// > = redirects direct TO the program/file proceeding the >
