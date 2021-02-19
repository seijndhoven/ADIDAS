#include <stdio.h>
#include <stdlib.h>

#include "encode.h"
#include "io.h"

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("Please provide file name arguments:\n");
        printf("%s inputfile outpfile\n", argv[0]);
        exit(0);
    }

    printf("%s: %s --> %s\n", argv[0], argv[1], argv[2]);

    char* input_file_name = argv[1];
    char* output_file_name = argv[2];

    bool success = io_open_file_for_reading(input_file_name);
    if (!success)
    {
        io_exit(1);
    }

    success = io_open_file_for_writing(output_file_name);
    if (!success)
    {
        io_exit(1);
    }

    uint8_t high = 0, low = 0;
    uint8_t byteRead = 0;
    while (io_read_byte(&byteRead))
    {
        encode_value(byteRead, &high, &low);

        success = io_write_byte(high);
        if (!success)
        {
            io_exit(1);
        }
        success = io_write_byte(low);
        if (!success)
        {
            io_exit(1);
        }
    }

    io_exit(0);

    return 0;
}
