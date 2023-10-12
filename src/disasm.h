#ifndef VDISASM
#define VDISASM

#include <stdio.h>

#define DEBUG

#ifdef DEBUG
#define ON_DEBUG(x) x
#else
#define ON_DEDUG(x)
#endif

enum disasm_error {
    DISASM_SUCCEED,
    DISASM_BAD_ALLOC,
    DISASM_CREAT_FAILURE,
    DISASM_FAILURE,
};

disasm_error DisAssemble(char *input, char *output);

#endif // VDISASM
