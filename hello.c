#include <math.h>
#include <stdio.h>
#include <emscripten/emscripten.h>

int int_sqrt_another(int x) {
  return sqrt(x);
}

int main(int argc, char ** argv) {
  printf("Easy FT8 Encoder ;)\n");

  // int z = int_sqrt_another(100);

  // printf("Test -> %d\n", z);

  return 0;
}

#ifdef __cplusplus
extern "C" {
#endif

int EMSCRIPTEN_KEEPALIVE int_sqrt(int x) {
  return sqrt(x);
}

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void EMSCRIPTEN_KEEPALIVE myFunction(int argc, char ** argv) {
  printf("MyFunction Called\n");
}

#ifdef __cplusplus
}
#endif
