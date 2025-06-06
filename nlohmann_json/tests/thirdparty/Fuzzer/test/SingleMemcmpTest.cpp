// This file is distributed under the University of Illinois Open src
// License. See LICENSE.TXT for details.

// Simple test for a fuzzer. The fuzzer must find a particular string.
#include <cstring>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  char *S = (char*)Data;
  if (Size >= 6 && !memcmp(S, "qwerty", 6)) {
    fprintf(stderr, "BINGO\n");
    exit(1);
  }
  return 0;
}
