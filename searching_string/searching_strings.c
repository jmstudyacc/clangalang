// get user input
// check against array holding song list
// confirm if input matches available song

#include <stdio.h>
#include <string.h>

// first set of brackets is for the array of ALL strings | second set is used for sizing each individual string
// in this case the array is an array of arrays (matrix) - this is global as all functions need to access it
char tracks[][80] = {
        "I left my heart in Harvard Med School",
        "Newark, Newark - a wonderful town",
        "Dancing with a Dork",
        "From here to maternity",
        "The girl from Iwo Jima",
};

void find_track(char search_for[]) {
    int i;
    int f = 0;
    for ( i = 0; i < 5; i++ ) {
        // this will search for the substring in the track list - this can flag multiple tracks!
        if (strstr(tracks[i], search_for))
            printf("Track %i: '%s'\n", i, tracks[i]);
        f = 1;
    }
    if ( f )
        printf("No tracks found containing search string: '%s'\n", search_for);
}

int main() {
    // creating the char array that will be searched for
    char search_for[80];
    puts("Please input your song selection:");
    // fgets is the better approach! 1) What data structure will have the import (2) How big is the import? (3) Where is it coming from?
    fgets(search_for, 80, stdin);
    // take the whole length, subtract 1 and insert '\0' so compiler knows where array ends
    search_for[strlen(search_for) - 1] = '\0';
    find_track(search_for);
    return 0;
}
