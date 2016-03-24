#include <stdlib.h>
#include <string.h>

#include "leftpad.h"

char* left_pad(char* base_str, const unsigned int times)
{
    return do_left_pad(base_str, times, ' ');
}

char* left_pad_str(char* base_str, const unsigned int times, const char pad_char)
{
    return do_left_pad(base_str, times, pad_char);
}

static
char* do_left_pad(char* base_str, const unsigned int times, const char pad_char)
{
    char* padded_str;
    int base_str_len = strlen(base_str);
    int index;

    if (0 == times) {
        return base_str;
    }

    // init new string
    padded_str = (char*) calloc(base_str_len + times + 1, sizeof(char));

    if (NULL == padded_str) {
        return NULL;
    }

    // Add left padding
    for (index = 0; index < times; ++index) {
        *(padded_str + index) = pad_char;
    }

    // Copy original string
    for (index = 0; index < base_str_len; ++index) {
        *(padded_str + times + index) = *(base_str + index);
    }

    return padded_str;
}