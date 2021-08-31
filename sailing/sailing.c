#include <stdio.h>

// function that prints out a pirate themed message defined in main
void pirate_saying(char msg[]) {    // as you cannot account for the String length pre-compile, the length of msg[] is unknown
    printf("Pirate saying reads: %s\n", msg);
    printf("The pirate saying occupies %i bytes in memory\n", sizeof(msg)); // 0n 64-bit machine this will return 8 bytes as that is the size of a pointer
}

// function that takes latitude and longitude values
void go_south_east(int *lat, int *lon) {
    *lat = *lat - 1;  // decrease the lat by 1
    *lon = *lon + 1;  // increase the lon by 1
    printf("Y'Arr! Values in the function are: [%i, %i]\n", *lat, *lon);
}

int main() {
    int latitude = 32;
    int longitude = -64;

    printf("Set sail! Start at: [%i, %i]\n", latitude, longitude);
    go_south_east(&latitude, &longitude);
    printf("Avast! Now at: [%i, %i]\n", latitude, longitude);

    char quote[] = "Batten down the hatches!";
    pirate_saying(quote);
}
