#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            float sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            float sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            float sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);


            if (sepiaRed > 255)
                image[i][j].rgbtRed = 255;
            else if (sepiaRed <= 255)
                image[i][j].rgbtRed = sepiaRed;

            if (sepiaGreen > 255)
                image[i][j].rgbtGreen = 255;
            else if (sepiaGreen <=255)
                image[i][j].rgbtGreen = sepiaGreen;

            if (sepiaBlue > 255)
                image[i][j].rgbtBlue = 255;
            else if (sepiaBlue <= 255)
                image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int red = 0;
    int green = 0;
    int blue = 0;

    for (int i = 0; i < height; i++)
    {
        int half = 0;

        if (width % 2 == 0)
        {
            half = width / 2;
        }
        else
        {
            half = (width + 1) / 2;
        }

        for (int j = 0; j < half; j++)
        {
            red = image[i][j].rgbtRed;
            green = image[i][j].rgbtGreen;
            blue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = red;
            image[i][width - j - 1].rgbtGreen = green;
            image[i][width - j - 1].rgbtBlue = blue;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int k = 0; k < height; k++)
    {
        for (int n = 0; n < width; n++)
        {
            float total_red = 0;
            float total_green = 0;
            float total_blue = 0;

            int last_row = k - 1;
            int last_column = n - 1;

            int row_number = 3;
            int column_number = 3;

            int cell_number = 0;

            if (last_row < 0)
            {
                last_row = k;
                row_number--;
            }
            if (last_column < 0)
            {
                last_column = n;
                column_number--;
            }
            if (k >= height - 1)
            {
                row_number--;
            }
            if (n >= width -1)
            {
                column_number--;
            }

            for (int l = last_row; l < (last_row + row_number); l++)
            {
                for (int m = last_column; m < (last_column + column_number); m++)
                {
                    total_red += copy[l][m].rgbtRed;
                    total_green += copy[l][m].rgbtGreen;
                    total_blue += copy[l][m].rgbtBlue;

                    cell_number++;
                }
            }

            image[k][n].rgbtRed = round(total_red / (cell_number));
            image[k][n].rgbtGreen = round(total_green / (cell_number));
            image[k][n].rgbtBlue = round(total_blue / (cell_number));
        }
    }

    return;
}