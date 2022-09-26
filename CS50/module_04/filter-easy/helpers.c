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

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE img[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img[i][j] = image [i][j];
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
                    int redx = 2 * img[i][j + 1].rgbtRed + img[i + 1][j + 1].rgbtRed;
                    int redy = 2 * img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed;
                    int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                    if (red <= 255)
                    {
                        image[i][j].rgbtRed = red;
                    }
                    else
                    {
                        image[i][j].rgbtRed = 255;
                    }

                    int greenx = 2 * img[i][j + 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                    int greeny = 2 * img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                    int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                    if (green <= 255)
                    {
                        image[i][j].rgbtGreen = green;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = 255;
                    }

                    int bluex = 2 * img[i][j + 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                    int bluey = 2 * img[i + 1][j].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                    int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

                    if (blue <= 255)
                    {
                        image[i][j].rgbtBlue = blue;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                }

                else if (j == width - 1)
                {
                    int redx = -2 * img[i][j - 1].rgbtRed - img[i + 1][j - 1].rgbtRed;
                    int redy = 2 * img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed;
                    int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                    if (red <= 255)
                    {
                        image[i][j].rgbtRed = red;
                    }
                    else
                    {
                        image[i][j].rgbtRed = 255;
                    }

                    int greenx = -2 * img[i][j - 1].rgbtGreen - img[i + 1][j - 1].rgbtGreen;
                    int greeny = 2 * img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen;
                    int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                    if (green <= 255)
                    {
                        image[i][j].rgbtGreen = green;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = 255;
                    }

                    int bluex = -2 * img[i][j - 1].rgbtBlue - img[i + 1][j - 1].rgbtBlue;
                    int bluey = 2 * img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue;
                    int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

                    if (blue <= 255)
                    {
                        image[i][j].rgbtBlue = blue;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                }

                else
                {
                    int redx = -2 * img[i][j - 1].rgbtRed - img[i + 1][j - 1].rgbtRed + 2 * img[i][j + 1].rgbtRed + img[i + 1][j + 1].rgbtRed;
                    int redy = 2 * img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed + img[i + 1][j + 1].rgbtRed;
                    int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                    if (red <= 255)
                    {
                        image[i][j].rgbtRed = red;
                    }
                    else
                    {
                        image[i][j].rgbtRed = 255;
                    }

                    int greenx = -2 * img[i][j - 1].rgbtGreen - img[i + 1][j - 1].rgbtGreen + 2 * img[i][j + 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                    int greeny = 2 * img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                    int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                    if (green <= 255)
                    {
                        image[i][j].rgbtGreen = green;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = 255;
                    }

                    int bluex = -2 * img[i][j - 1].rgbtBlue - img[i + 1][j - 1].rgbtBlue + 2 * img[i][j + 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                    int bluey = 2 * img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                    int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

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

            else if (i == height - 1)
            {
                if (j == 0)
                {
                    int redx = 2 * img[i][j + 1].rgbtRed + img[i - 1][j + 1].rgbtRed;
                    int redy = -2 * img[i - 1][j].rgbtRed - img[i - 1][j + 1].rgbtRed;
                    int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                    if (red <= 255)
                    {
                        image[i][j].rgbtRed = red;
                    }
                    else
                    {
                        image[i][j].rgbtRed = 255;
                    }

                    int greenx = 2 * img[i][j + 1].rgbtGreen + img[i - 1][j + 1].rgbtGreen;
                    int greeny = -2 * img[i - 1][j].rgbtGreen - img[i - 1][j + 1].rgbtGreen;
                    int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                    if (green <= 255)
                    {
                        image[i][j].rgbtGreen = green;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = 255;
                    }

                    int bluex = 2 * img[i][j + 1].rgbtBlue + img[i - 1][j + 1].rgbtBlue;
                    int bluey = -2 * img[i - 1][j].rgbtBlue - img[i - 1][j + 1].rgbtBlue;
                    int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

                    if (blue <= 255)
                    {
                        image[i][j].rgbtBlue = blue;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                }

                else if (j == width - 1)
                {
                    int redx = -2 * img[i][j - 1].rgbtRed - img[i - 1][j - 1].rgbtRed;
                    int redy = -2 * img[i - 1][j].rgbtRed - img[i - 1][j - 1].rgbtRed;
                    int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                    if (red <= 255)
                    {
                        image[i][j].rgbtRed = red;
                    }
                    else
                    {
                        image[i][j].rgbtRed = 255;
                    }

                    int greenx = -2 * img[i][j - 1].rgbtGreen - img[i - 1][j - 1].rgbtGreen;
                    int greeny = -2 * img[i - 1][j].rgbtGreen - img[i - 1][j - 1].rgbtGreen;
                    int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                    if (green <= 255)
                    {
                        image[i][j].rgbtGreen = green;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = 255;
                    }

                    int bluex = -2 * img[i][j - 1].rgbtBlue - img[i - 1][j - 1].rgbtBlue;
                    int bluey = -2 * img[i - 1][j].rgbtBlue - img[i - 1][j + 1].rgbtBlue;
                    int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

                    if (blue <= 255)
                    {
                        image[i][j].rgbtBlue = blue;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                }

                else
                {
                    int redx = -2 * img[i][j - 1].rgbtRed - img[i - 1][j - 1].rgbtRed + 2 * img[i][j + 1].rgbtRed + img[i - 1][j + 1].rgbtRed;
                    int redy = -2 * img[i - 1][j].rgbtRed - img[i - 1][j - 1].rgbtRed - img[i - 1][j + 1].rgbtRed;
                    int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                    if (red <= 255)
                    {
                        image[i][j].rgbtRed = red;
                    }
                    else
                    {
                        image[i][j].rgbtRed = 255;
                    }

                    int greenx = -2 * img[i][j - 1].rgbtGreen - img[i - 1][j - 1].rgbtGreen + 2 * img[i][j + 1].rgbtGreen + img[i - 1][j + 1].rgbtGreen;
                    int greeny = -2 * img[i - 1][j].rgbtGreen - img[i - 1][j - 1].rgbtGreen - img[i - 1][j + 1].rgbtGreen;
                    int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                    if (green <= 255)
                    {
                        image[i][j].rgbtGreen = green;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = 255;
                    }

                    int bluex = -2 * img[i][j - 1].rgbtBlue - img[i - 1][j - 1].rgbtBlue + 2 * img[i][j + 1].rgbtBlue + img[i - 1][j + 1].rgbtBlue;
                    int bluey = -2 * img[i - 1][j].rgbtBlue - img[i - 1][j - 1].rgbtBlue - img[i - 1][j + 1].rgbtBlue;
                    int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

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

            else if (j == 0)
            {
                int redx = 2 * img[i][j + 1].rgbtRed + img[i - 1][j + 1].rgbtRed + img[i + 1][j + 1].rgbtRed;
                int redy = -2 * img[i - 1][j].rgbtRed - img[i - 1][j + 1].rgbtRed + 2 * img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed;
                int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                if (red <= 255)
                {
                    image[i][j].rgbtRed = red;
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                int greenx = 2 * img[i][j + 1].rgbtGreen + img[i - 1][j + 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                int greeny = -2 * img[i - 1][j].rgbtGreen - img[i - 1][j + 1].rgbtGreen + 2 * img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                if (green <= 255)
                {
                    image[i][j].rgbtGreen = green;
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                int bluex = 2 * img[i][j + 1].rgbtBlue + img[i - 1][j + 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                int bluey = -2 * img[i - 1][j].rgbtBlue - img[i - 1][j + 1].rgbtBlue + 2 * img[i + 1][j].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

                if (blue <= 255)
                {
                    image[i][j].rgbtBlue = blue;
                }
                else
                {
                    image[i][j].rgbtBlue = 255;
                }
            }

            else if (j == width - 1)
            {
                int redx = -2 * img[i][j - 1].rgbtRed - img[i - 1][j - 1].rgbtRed - img[i + 1][j - 1].rgbtRed;
                int redy = -2 * img[i - 1][j].rgbtRed - img[i - 1][j - 1].rgbtRed + 2 * img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed;
                int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                if (red <= 255)
                {
                    image[i][j].rgbtRed = red;
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                int greenx = -2 * img[i][j - 1].rgbtGreen - img[i - 1][j - 1].rgbtGreen - img[i + 1][j - 1].rgbtGreen;
                int greeny = -2 * img[i - 1][j].rgbtGreen - img[i - 1][j - 1].rgbtGreen + 2 * img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen;
                int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                if (green <= 255)
                {
                    image[i][j].rgbtGreen = green;
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                int bluex = -2 * img[i][j - 1].rgbtBlue - img[i - 1][j - 1].rgbtBlue - img[i + 1][j - 1].rgbtBlue;
                int bluey = -2 * img[i - 1][j].rgbtBlue - img[i - 1][j - 1].rgbtBlue + 2 * img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue;
                int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

                if (blue <= 255)
                {
                    image[i][j].rgbtBlue = blue;
                }
                else
                {
                    image[i][j].rgbtBlue = 255;
                }
            }

            else
            {
                int redx = -2 * img[i][j - 1].rgbtRed - img[i - 1][j - 1].rgbtRed - img[i + 1][j - 1].rgbtRed + 2 * img[i][j + 1].rgbtRed + img[i - 1][j + 1].rgbtRed + img[i + 1][j + 1].rgbtRed;
                int redy = -2 * img[i - 1][j].rgbtRed - img[i - 1][j - 1].rgbtRed - img[i - 1][j + 1].rgbtRed + 2 * img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed + img[i + 1][j + 1].rgbtRed;
                int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                if (red <= 255)
                {
                    image[i][j].rgbtRed = red;
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                int greenx = -2 * img[i][j - 1].rgbtGreen - img[i - 1][j - 1].rgbtGreen - img[i + 1][j - 1].rgbtGreen + 2 * img[i][j + 1].rgbtGreen + img[i - 1][j + 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                int greeny = -2 * img[i - 1][j].rgbtGreen - img[i - 1][j - 1].rgbtGreen - img[i - 1][j + 1].rgbtGreen + 2 * img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                if (green <= 255)
                {
                    image[i][j].rgbtGreen = green;
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                int bluex = -2 * img[i][j - 1].rgbtBlue - img[i - 1][j - 1].rgbtBlue - img[i + 1][j - 1].rgbtBlue + 2 * img[i][j + 1].rgbtBlue + img[i - 1][j + 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                int bluey = -2 * img[i - 1][j].rgbtBlue - img[i - 1][j - 1].rgbtBlue - img[i - 1][j + 1].rgbtBlue + 2 * img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

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
    }
    return;
}