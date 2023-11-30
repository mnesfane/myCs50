#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';
        //allocate memo for to copy the ...
        plates[idx] = malloc(strlen(buffer) + 1);
        strcpy(plates[idx], buffer);
        // printf("//%lu//\n", strlen(buffer) + 1);
        // exit (0);
        // printf("//%s//\n", plates[idx]);

        // Save plate number in array
        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        free(plates[i]);
    }
}
