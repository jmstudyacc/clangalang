//
// Created by James Miles on 31/08/2021.
//

// You may need to create your own data streams - the OS will allow you to do this
// these streams will go beyond Stdin, Stdout, Stderr

/*

Each data stream is represented by a pointer to a file and you can create a new data stream with fopen()

 FILE *in_file (This will create a data stream to read FROM a file)
--------------> = fopen("input.txt, "r"); ( fopen() specifies the name of the file and the mode to be used)

FILE *out_file (This will create a data stream to read TO a file)
--------------> = fopen("output.txt, "w");

fopen() takes 2 parameters: a filename and a mode (a: append, r: read, w: write)

DON'T FORGET!!! CLOSE YOUR DATA STREAM WHEN YOU ARE FINISHED WITH IT!!!
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char line[80];

    if ( argc != 6 )
    {
        fprintf(stderr, "You need to provide 5 arguments.\n");
        return 1;
    }

    //FILE *in = fopen("spooky.csv", "r");

    FILE *in;
    // include error checking if the file doesn't exist
    if ( !(in = fopen("spooky.csv", "r")))  // if in cannot be assigned to fopen() then...
    {
        fprintf(stderr, "Can't open the file.\n");
        return 1;
    }

    FILE *file1 = fopen(argv[2], "w");
    FILE *file2 = fopen(argv[4], "w");
    FILE *file3 = fopen(argv[5], "w");

    while (fscanf(in, "%79[^\n]\n", line) == 1)
    {
        if ( strstr(line, argv[1]))
            fprintf(file1, "%s\n", line);
        else if (strstr(line, argv[3]))
            fprintf(file2, "%s\n", line);
        else
            fprintf(file3, "%s\n", line);
    }
    // There are a limited number of file streams available for processes - close unused ones!!
    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(in);
    return 0;
}