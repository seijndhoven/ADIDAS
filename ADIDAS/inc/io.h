#ifndef IO_H_
#define IO_H_

#include <stdbool.h>
#include <stdint.h>

bool io_open_file_for_writing(char* file_name);
bool io_write_byte(uint8_t b);
bool io_close_file_for_writing();

bool io_open_file_for_reading(char* file_name);
bool io_read_byte(uint8_t* b);
bool io_close_file_for_reading();

void io_exit(int result);

#endif
