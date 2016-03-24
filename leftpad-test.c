#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leftpad.h"

int do_test(char* a, char *b)
{
    return 0 != strcmp(a, b);
}

int main(void) {
    char* lastCheck = (char*) calloc(10001, sizeof(char));
    int i;

    if (NULL == lastCheck) {
        printf("Unable to launch the test. Please free some KB of ram.");
        return EXIT_FAILURE;
    }

    for (i = 0; i < 10000; ++i) {
        *(lastCheck + i) = 'a';
    }

    if (do_test(left_pad("foo", 0), "foo")) {
        printf("Test failed: left_pad(\"foo\", 0) != \"foo\"\n");
        return EXIT_FAILURE;
    }

    if (do_test(left_pad("foo", 3), "   foo")) {
        printf("Test failed: left_pad(\"foo\", 3) != \"   foo\"\n");
        return EXIT_FAILURE;
    }

    if (do_test(left_pad_str("foo", 5, 'a'), "aaaaafoo")) {
        printf("Test failed: left_pad_str(\"foo\", 5, 'a') != \"aaaaafoo\"\n");
        return EXIT_FAILURE;
    }

    if (do_test(left_pad_str("", 10000, 'a'), lastCheck)) {
        printf("Test failed: left_pad_str(\"\", 10000, 'a') != 10000x'a'\n");
        return EXIT_FAILURE;
    }

    printf("All tests passed \\o/\n");
    return EXIT_SUCCESS;
}