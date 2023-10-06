#include "disasm.h"
#include "asm.h"
#include <assert.h>

static const size_t MAXSTR = 1000; ///< max string lenght

static cmd_error parse_cmd(const char *cmd, FILE *outp);

int DisAssembly(const char *input, const char *output) {
    assert(input);
    assert(output);

    return process_input(input, output, parse_cmd);
}

static cmd_error parse_cmd(const char *cmd, FILE *outp) {
    assert(cmd);
    assert(outp);

    int cmd_code = 0;

    if (sscanf(cmd, "%d", &cmd_code) <= 0) {
        return UNKNOWN;
    }

    double arg = 0;

    for (size_t i = 0; i < sizeof(CMD_LIST) / sizeof(Command); i++) {
        if (cmd_code == CMD_LIST[i].code) {
            if (CMD_LIST[i].nargs) {
                if (sscanf(cmd, "%*s %lf", &arg) <= 0) {
                    return NO_ARG;
                }

                fprintf(outp, "%s %lf\n", CMD_LIST[i].name, arg);
                return SUCCESS;
            }

            fprintf(outp, "%s\n", CMD_LIST[i].name);
            return SUCCESS;
        }
    }

    return UNKNOWN;
}
