#include <cstdlib>
#include <stdlib.h>
#include "error_processing.h"
#include "assembler_funcs.h"

int main() {
    asm_err last_err = ASM_ERR_OK;

    asm_data_t asm_data = {}; asm_data_t_ctor(&asm_data);

    asm_code_read(&asm_data.asm_code, "./../asm_code.txt", &last_err);
    if (last_err != ASM_ERR_OK) {
        DEBUG_ERROR(last_err);
        return EXIT_FAILURE;
    }

    asm_commands_translate(&asm_data, &last_err);

    bin_code_write("./../bin_code.txt", asm_data.bin_code, &last_err);

    return EXIT_SUCCESS;
}
