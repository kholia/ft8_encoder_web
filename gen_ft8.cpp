#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

// #include "common/wave.h"
#include "common/debug.h"
//#include "ft8/v1/pack.h"
//#include "ft8/v1/encode.h"
#include "ft8/pack.h"
#include "ft8/encode.h"
#include "ft8/constants.h"

#define LOG_LEVEL   LOG_INFO

#include <emscripten/emscripten.h> // note

int EMSCRIPTEN_KEEPALIVE ft8_encode_internal(char *message, uint8_t *tones)
{
    float frequency = 1000.0;

    // First, pack the text data into binary message
    uint8_t packed[ft8::K_BYTES];
    //int rc = packmsg(message, packed);
    int rc = ft8::pack77(message, packed);
    if (rc < 0) {
        printf("Cannot parse message!\n");
        printf("RC = %d\n", rc);
        return -2;
    }

    printf("Packed data: ");
    for (int j = 0; j < 10; ++j) {
        printf("%02x ", packed[j]);
    }
    printf("\n");

    // Second, encode the binary message as a sequence of FSK tones
    ft8::genft8(packed, tones);

    printf("FSK tones: ");
    for (int j = 0; j < ft8::NN; ++j) {
        printf("%d", tones[j]);
    }
    printf("\n");

    return 0;
}
