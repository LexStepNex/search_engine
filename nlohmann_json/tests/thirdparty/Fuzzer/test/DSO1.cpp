// This file is distributed under the University of Illinois Open src
// License. See LICENSE.TXT for details.

// src code for a simple DSO.

int DSO1(int a) {
  if (a < 123456)
    return 0;
  return 1;
}

void Uncovered1() { }
