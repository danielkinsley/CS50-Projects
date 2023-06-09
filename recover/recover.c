#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check that the argument count is 2
    if (argc != 2)
    {
        printf("Usage: ./recover Image\n");
        return 1;
    }

    // Open file for reading

    FILE *input_file = fopen(argv[1], "r");

    // check that the input file is valid

    if (input_file == NULL)
    {
        printf("Could not open file");
        return 2;
    }

    // store blocks of 512 bytes in array
    unsigned char buffer[512];

    // track number of images generated
    int count_image = 0;

    // file pointer for recovered images
    FILE *output_file = NULL;

    // char filename[8]
    char *filename = malloc(8 * sizeof(char));

    // Read the blocks of 512 bytes
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        // Check if bytes indicate start of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Write the JPEG file names
            sprintf(filename, "%03i.jpg", count_image);

            // OPen output_file for writing
            output_file = fopen(filename, "w");

            // count number of images found
            count_image++;
        }
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}