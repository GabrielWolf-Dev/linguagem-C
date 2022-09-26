#include <math.h>
#include "helpers.h"

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int average = round((red + green + blue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE img[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = round(0.393 * img[i][j].rgbtRed + 0.769 * img[i][j].rgbtGreen + 0.189 * img[i][j].rgbtBlue);
            int green = round(0.349 * img[i][j].rgbtRed + 0.686 * img[i][j].rgbtGreen + 0.168 * img[i][j].rgbtBlue);
            int blue = round(0.272 * img[i][j].rgbtRed + 0.534 * img[i][j].rgbtGreen + 0.131 * img[i][j].rgbtBlue);

            if (red <= 255)
            {
                image[i][j].rgbtRed = red;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }

            if (green <= 255)
            {
                image[i][j].rgbtGreen = green;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }

            if (blue <= 255)
            {
                image[i][j].rgbtBlue = blue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE aux;

        int start = 0;
        int end = width - 1;

        while (start < end)
        {
            aux = image[i][start];
            image[i][start] = image[i][end];
            image[i][end] = aux;

            start++;
            end--;
        }
    }
    return;
}

// Desfoca imagem
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE img[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j + 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j + 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j + 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j + 1].rgbtBlue) / 4.0);
                }

                else if (j == width - 1)
                {
                    image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j - 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j - 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j - 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue) / 4.0);
                }

                else
                {
                    image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j - 1].rgbtRed + img[i][j + 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed + img[i + 1][j + 1].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j - 1].rgbtGreen + img[i][j + 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j - 1].rgbtBlue + img[i][j + 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue) / 6.0);
                }
            }

            else if (i == height - 1)
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j + 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j + 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j + 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j + 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j + 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j + 1].rgbtBlue) / 4.0);
                }

                else if (j == width - 1)
                {
                    image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j - 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j - 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j - 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j - 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j - 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j - 1].rgbtBlue) / 4.0);
                }

                else
                {
                    image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j - 1].rgbtRed + img[i][j + 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j - 1].rgbtRed + img[i - 1][j + 1].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j - 1].rgbtGreen + img[i][j + 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j - 1].rgbtGreen + img[i - 1][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j - 1].rgbtBlue + img[i][j + 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j - 1].rgbtBlue + img[i - 1][j + 1].rgbtBlue) / 6.0);
                }
            }

            else if (j == 0)
            {
                image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j + 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j + 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j + 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j + 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j + 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j + 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j + 1].rgbtBlue) / 6.0);
            }

            else if (j == width - 1)
            {
                image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j - 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j - 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j - 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j - 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j - 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j - 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue) / 6.0);
            }

            else
            {
                image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i - 1][j - 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j + 1].rgbtRed + img[i][j - 1].rgbtRed + img[i][j + 1].rgbtRed + img[i + 1][j - 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed) / 9.0);
                image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i - 1][j - 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j + 1].rgbtGreen + img[i][j - 1].rgbtGreen + img[i][j + 1].rgbtGreen + img[i + 1][j - 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen) / 9.0);
                image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i - 1][j - 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j + 1].rgbtBlue + img[i][j - 1].rgbtBlue + img[i][j + 1].rgbtBlue + img[i + 1][j - 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j + 1].rgbtBlue) / 9.0);
            }
        }
    }
    return;
}