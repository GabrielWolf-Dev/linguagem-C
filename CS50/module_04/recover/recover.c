#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Use: ./recover file_name");

        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("The file cannot be opened\n");

        return 1;
    }

    BYTE buffer[512];

    int counter = 0;

    FILE *jpeg = NULL;

    char *filename = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(BYTE), 512, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            if (buffer[3] == 0xe0 || buffer[3] == 0xe1 || buffer[3] == 0xe2 || buffer[3] == 0xe3 || buffer[3] == 0xe4 || buffer[3] == 0xe5
                || buffer[3] == 0xe6 || buffer[3] == 0xe7 || buffer[3] == 0xe8 || buffer[3] == 0xe9 || buffer[3] == 0xea || buffer[3] == 0xeb
                || buffer[3] == 0xec || buffer[3] == 0xed || buffer[3] == 0xee || buffer[3] == 0xef)
            {
                sprintf(filename, "%03i.jpg", counter);

                jpeg = fopen(filename, "w");

                counter++;
            }
        }

        if (jpeg != NULL)
        {
            fwrite(buffer, sizeof(char), 512, jpeg);
        }
    }

    fclose(file);
    fclose(jpeg);

    free(filename);

    return 0;
}