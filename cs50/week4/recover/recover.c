#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t byte;
//  pseudocode
// check if the argv input is correct
// point to the file
// read 512 bytes while true
// see if the data it's a start of jpeg file
//name the jpeg file ###.jpeg change the filename by sprintf (print in the string)
// write that data to new jpeg file
// while writing data check if the next 512 B blocks is a jpeg start file
int main(int ac, char *av[])
{
    bool s = false;
    FILE *img;
    FILE *hold ;
    int jpegn = 0;
    if (ac != 2)
    {
        return (printf("retard\n"), 1);
    }
    FILE *inptr = fopen(av[1], "r");
    if (!inptr)
    {
        return (printf("cannot open the file\n"), 1);
    }
    byte *buff = malloc(sizeof(byte) * 512);
    while (fread(buff, sizeof(byte), 512, inptr) == 512)
    {
        if (buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff)
        {
            byte b = buff[3] & 0xf0;
            b = buff[3] - b;
            if (b >= 0 && b <= 15)
            {
                if (s)
                {
                    fclose(img);
                }
                s = true;
                char filename[9];
                sprintf(filename, "%03d.jpg", jpegn);
                img = fopen(filename, "w");
                jpegn++;
            }
        }
        if (s)
        {
            fwrite(buff, sizeof(byte), 512, img);

        }
    }
    free(buff);
    fclose(img);
    fclose(inptr);
    return (0);
}