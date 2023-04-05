#include "coder.h"
#include "command.h"
#include <inttypes.h>
#include <stdio.h>

int encode(uint32_t code_point, CodeUnits *code_units)
{
    if (code_point < 0x80)
    {
        code_units->length = 1;
        code_units->code[0] = code_point;
    }

    else if (code_point < 0x800)
    {
        code_units->length = 2;
        code_units->code[0] = 0xc0 | code_point >> 6;
        code_units->code[1] = 0x80 | (code_point & 0x3f);
    }
    else if (code_point < 0x10000)
    {
        code_units->length = 3;
        code_units->code[0] = 0xe0 | (code_point >> 12);
        code_units->code[1] = 0x80 | ((code_point >> 6) & 0x3f);
        code_units->code[2] = 0x80 | (code_point & 0x3f);
    }
    else if (code_point < 0x100000)
    {
        code_units->length = 4;
        code_units->code[0] = 0xf0 | (code_point >> 18);
        code_units->code[1] = 0x80 | ((code_point >> 12) & 0x3f);
        code_units->code[2] = 0x80 | ((code_point >> 6) & 0x3f);
        code_units->code[3] = 0x80 | (code_point & 0x3f);
    }
    else
        return -1;
    return 0;
}

uint32_t decode(const CodeUnits *code_unit)
{
    uint32_t value;
    if (code_unit->length == 1)
    {
        value = code_unit->code[0];
    }
    else if (code_unit->length == 2)
    {
        value = code_unit->code[0];
    }
    else
        return -1;
    return value;
}

int read_next_code_unit(FILE *in, CodeUnits *code_units)
{
    return 0;
}

int write_code_unit(FILE *out, const CodeUnits *code_units)
{
    int result = fwrite(code_units->code, 1, code_units->length, out);
    return result;
}