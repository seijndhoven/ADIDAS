#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "channel.h"
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

    channel_init();

    uint8_t byteRead = 0;
    bool isEven = false;
    uint32_t index = 0;

    while (io_read_byte(&byteRead))
    {
        isEven = (index % 2) == 0;
        if (isEven)
        {
            byteRead = channel_change_one_random_bit(byteRead);
        }

        success = io_write_byte(byteRead);
        if (!success)
        {
            io_exit(1);
        }
        index++;
    }

    io_exit(0);

    return 0;
}
