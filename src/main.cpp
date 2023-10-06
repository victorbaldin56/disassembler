#include "disasm.h"
#include "colors.h"
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf(FG_RED);
        printf("VDisAssembler: no input files\n");
        printf(RESET);
        return -1;
    }

    if (argc == 4 && !strcmp(argv[3], "-o")) {
        return DisAssembly(argv[1], argv[3]);
    }

    return DisAssembly(argv[1], "disasm.txt");
}
