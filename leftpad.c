#include <stdlib.h>
#include <string.h>

#include "leftpad.h"

static char *do_left_pad(const char* base_str, size_t new_size, char pad_char);

char* left_pad(const char* base_str, size_t new_size)
{
    return do_left_pad(base_str, new_size, ' ');
}

char* left_pad_str(const char* base_str, size_t new_size, char pad_char)
{
    return do_left_pad(base_str, new_size, pad_char);
}

static
char* do_left_pad(const char* base_str, size_t new_size, char pad_char)
{
    char* padded_str;
    size_t diff, base_str_len = strlen(base_str);

    if (base_str_len >= new_size) {
        return strdup(base_str);
    }

    // new_size > base_str_len

    // init new string
    padded_str = (char*) calloc(new_size + 1, sizeof(char));
    diff = new_size - base_str_len;

    if (NULL == padded_str) {
        return NULL;
    }

    // Add left padding
    memset(padded_str, pad_char, diff);

    // Copy original string
    strncpy(padded_str+diff, base_str, base_str_len * sizeof(char));

    return padded_str;
}
