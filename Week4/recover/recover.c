#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE \n");
        return 1;
    }

    FILE *card = fopen(argv[1] , "r");
    if (card == NULL)
    {
        printf("Unable to open file. \n");
        return 1;
    }

    typedef uint8_t BYTE;
    const int BLOCK_SIZE = 512;

    BYTE *buffer = malloc(sizeof(BYTE) * BLOCK_SIZE);

    int file_number = 0;
    char *filename = malloc(8);
    int first_file = 0;

    FILE *jpeg = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (first_file == 1)
            {
                fclose(jpeg);
            }

            sprintf(filename, "%03i.jpg", file_number);
            jpeg = fopen(filename , "w");

            first_file = 1;
            file_number++;
        }

        if (first_file == 1)
        {
            fwrite(buffer, 1, BLOCK_SIZE, jpeg);
        }
    }

    fclose(jpeg);
    fclose(card);
    free(buffer);
    free(filename);
}