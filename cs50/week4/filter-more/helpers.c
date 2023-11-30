#include "helpers.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float c = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            c += image[i][j].rgbtRed;
            c += image[i][j].rgbtGreen;
            c += image[i][j].rgbtBlue;
            c /= 3;
            c = round(c);
            image[i][j].rgbtRed = c;
            image[i][j].rgbtGreen = c;
            image[i][j].rgbtBlue = c;
            c = 0;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i = 0;
    int j = 0;
    //buff it's a struct variable to swap pixels
    RGBTRIPLE buff;
    //loop over every row and swap pixels
    while (i < height)
    {
        int w = width - 1;
        while (j < w)
        {
            buff = image[i][w];
            image[i][w] = image[i][j];
            image[i][j] = buff;
            j++;
            w--;
        }
        i++;
        j = 0;
    }
    return;
}


void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE org[height][width];
    float countr, countg, countb;
    countr = countg = countb = 0;
    int count = 0;

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            org[row][col] = image[row][col];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            for (int ptrrow = row - 1; ptrrow <= row + 1; ptrrow++)
            {
                for (int ptrcol = col - 1; ptrcol <= col + 1; ptrcol++)
                {
                    if (ptrrow < height && ptrcol < width && ptrrow >= 0 && ptrcol >= 0)
                    {
                        countr += org[ptrrow][ptrcol].rgbtRed;
                        countg += org[ptrrow][ptrcol].rgbtGreen;
                        countb += org[ptrrow][ptrcol].rgbtBlue;
                        count++;
                    }
                }
            }
            image[row][col].rgbtRed = round(countr / count);
            image[row][col].rgbtGreen = round(countg / count);
            image[row][col].rgbtBlue = round(countb / count);
            countr = countg = countb = 0;
            count = 0;
        }
    }
    return;
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE old[height][width];
    int gxr, gxg, gxb;
    int gyr, gyg, gyb;
    int gr, gg, gb;
    int i, j;
    int k, f;

    gxr = gxg = gxb = 0;
    gyr = gyg = gyb = 0;
    i = j = k = f = 0;
    int xmatrix[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1},
    };
    int ymatrix[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1},
    };

    for (int row = 0; row < height ; row++)
    {
        for (int col = 0; col < width; col++)
        {
            old[row][col] = image[row][col];
        }
    }
    for (int row = 0; row < height ; row++)
    {
        for (int col = 0; col < width; col++)
        {
            for (int ptrrow = row - 1; ptrrow <= row + 1; ptrrow++)
            {
                for (int ptrcol = col - 1; ptrcol <= col + 1; ptrcol++)
                {
                    if (ptrrow < height && ptrcol < width && ptrrow >= 0 && ptrcol >= 0)
                    {
                        RGBTRIPLE pxl = old[ptrrow][ptrcol];
                        gxr += xmatrix[i][j] * pxl.rgbtRed;
                        gxg += xmatrix[i][j] * pxl.rgbtGreen;
                        gxb += xmatrix[i][j] * pxl.rgbtBlue;

                        gyr += ymatrix[i][j] * pxl.rgbtRed;
                        gyg += ymatrix[i][j] * pxl.rgbtGreen;
                        gyb += ymatrix[i][j] * pxl.rgbtBlue;
                    }
                    j++;
                }
                j = 0;
                i++;
            }
            gr = round(sqrt(pow(gxr, 2) + pow(gyr, 2)));
            gg = round(sqrt(pow(gxg, 2) + pow(gyg, 2)));
            gb = round(sqrt(pow(gxb, 2) + pow(gyb, 2)));
            if (gr <= 255)
            {
                image[row][col].rgbtRed = gr;
            }
            else
            {
                image[row][col].rgbtRed = 255;
            }
            if (gg <= 255)
            {
                image[row][col].rgbtGreen = gg;
            }
            else
            {
                image[row][col].rgbtGreen = 255;
            }
            if (gb <= 255)
            {
                image[row][col].rgbtBlue = gb;
            }
            else
            {
                image[row][col].rgbtBlue = 255;
            }
            gxr = gxg = gxb = 0;
            gyr = gyg = gyb = 0;
            i = 0;
        }
    }
    return;
}