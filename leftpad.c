#include <stdlib.h>
#include <string.h>

#include "leftpad.h"

char* left_pad(char* base_str, const unsigned int new_size)
{
    return do_left_pad(base_str, new_size, ' ');
}

char* left_pad_str(char* base_str, const unsigned int new_size, const char pad_char)
{
    return do_left_pad(base_str, new_size, pad_char);
}

static
char* do_left_pad(char* base_str, const unsigned int new_size, const char pad_char)
{
    char* padded_str;
    int index, diff, base_str_len = strlen(base_str);

    if (0 == new_size) {
        return "";
    } else if (base_str_len > new_size) {
        // truncate original string
        padded_str = (char*) calloc(new_size + 1, sizeof(char));

        for (index = 0; index < new_size; ++index) {
            *(padded_str + index) = *(base_str + index);
        }

        return padded_str;
    } else if (base_str_len == new_size) {
        return base_str;
    }

    // new_size > base_str_len

    // init new string
    padded_str = (char*) calloc(new_size + 1, sizeof(char));
    diff = new_size - base_str_len;

    if (NULL == padded_str) {
        return NULL;
    }

    // Add left padding
    for (index = 0; index < diff; ++index) {
        *(padded_str + index) = pad_char;
    }

    // Copy original string
    for (index = 0; index < base_str_len; ++index) {
        *(padded_str + diff + index) = *(base_str + index);
    }

    return padded_str;
}