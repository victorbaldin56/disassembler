#ifndef VDISASM
#define VDISASM

#include <stdio.h>

#define DEBUG

#ifdef DEBUG
#define ON_DEBUG(x) x
#else
#define ON_DEDUG(x)
#endif

int DisAssembly(const char *input, const char *output);

#endif // VDISASM
