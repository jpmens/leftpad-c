#ifndef LEFTPAD_C_LEFTPAD_H
#define LEFTPAD_C_LEFTPAD_H

char* left_pad(char* base_str, const unsigned int times);
char* left_pad_str(char* base_str, const unsigned int times, const char pad_char);

static
char* do_left_pad(char* base_str, const unsigned int times, const char pad_char);

#endif //LEFTPAD_C_LEFTPAD_H
