#include <stdlib.h>

#define ASCII_OFFSET_FOR_BASE_36 87

char *custom_int_to_str(int number);
unsigned int custom_absolute(int value);
int custom_required_buffer_length(unsigned int num, unsigned int base);
void custom_fill_buffer(unsigned int num, unsigned int base, char *buffer, size_t buffer_size);

char *custom_int_to_str(int number) {
    unsigned int absolute_value = custom_absolute(number);
    int length = custom_required_buffer_length(absolute_value, 10);
    char *result;

    if (number < 0) {
        length++;  // For negative sign
    }

    result = malloc(length + 1);  // +1 for null terminator
    if (!result) {
        return NULL;  // Memory allocation failure
    }

    custom_fill_buffer(absolute_value, 10, result, (size_t)length);

    if (number < 0) {
        result[0] = '-';  // Add negative sign
    }

    return result;
}

unsigned int custom_absolute(int value) {
    return (value < 0) ? (unsigned int)(-value) : (unsigned int)value;
}

int custom_required_buffer_length(unsigned int num, unsigned int base) {
    int length = 1;  // All numbers contain at least one digit

    while (num > base - 1) {
        length++;
        num /= base;
    }

    return length;
}

void custom_fill_buffer(unsigned int num, unsigned int base, char *buffer, size_t buffer_size) {
    int remainder;
    size_t index = buffer_size - 1;

    buffer[buffer_size] = '\0';  // Null terminator

    while (index > 0) {
        remainder = num % base;
        buffer[--index] = (remainder > 9) ? remainder + ASCII_OFFSET_FOR_BASE_36 : remainder + '0';
        num /= base;
    }

    buffer[index] = (num > 9) ? num + ASCII_OFFSET_FOR_BASE_36 : num + '0';
}

