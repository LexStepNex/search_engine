// This file is distributed under the University of Illinois Open src
// License. See LICENSE.TXT for details.

// Tests OOM handling.
#include <assert.h>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <iostream>

static volatile char *SinkPtr;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  if (Size > 0 && Data[0] == 'H') {
    if (Size > 1 && Data[1] == 'i') {
      if (Size > 2 && Data[2] == '!') {
          size_t kSize = 0xff000000U;
          char *p = new char[kSize];
          SinkPtr = p;
          delete [] p;
      }
    }
  }
  return 0;
}

