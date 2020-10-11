#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>

#include <emscripten/emscripten.h> // note

int ft8_encode_internal(char *message, uint8_t *tones);

extern "C" {
int EMSCRIPTEN_KEEPALIVE ft8_encode(char *message, uint8_t *tones)
{
    return ft8_encode_internal(message, tones);

    return 0;
}
}
